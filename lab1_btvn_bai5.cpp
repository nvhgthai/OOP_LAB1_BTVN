#include <iostream>
#include <vector>
using namespace std;

void TimHinhChuNhat(const vector<vector<int>>& maTran, vector<vector<int>>& hinhChuNhat, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (maTran[i][j] == 1) {
                // Kiểm tra nếu đây là gốc của một hình chữ nhật
                int w = 0, h = 0;

                // Tính chiều rộng
                while (j + w < n && maTran[i][j + w] == 1) {
                    ++w;
                }

                // Tính chiều cao
                while (i + h < m && maTran[i + h][j] == 1) {
                    // Kiểm tra chiều rộng của các hàng tiếp theo
                    bool valid = true;
                    for (int k = 0; k < w; ++k) {
                        if (maTran[i + h][j + k] != 1) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        ++h;
                    } else {
                        break;
                    }
                }

                // Kiểm tra kích thước tối thiểu
                if (w >= 2 && h >= 2) {
                    hinhChuNhat.push_back({j, i, w, h});
                }
            }
        }
    }
}

int main() {
    int m, n;
    cout << "Nhap kich thuoc ma tran (m n): ";
    cin >> m >> n;

    vector<vector<int>> maTran(m, vector<int>(n));
    cout << "Nhap ma tran nhii phan (0 hoac 1):\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> maTran[i][j];
        }
    }

    vector<vector<int>> hinhChuNhat; // Lưu danh sách các hình chữ nhật
    TimHinhChuNhat(maTran, hinhChuNhat, m, n);

    cout << "Danh sach cac hinh chu nhat (x, y, w, h):\n";
    for (const auto& hcn : hinhChuNhat) {
        cout << "[" << hcn[0] << ", " << hcn[1] << ", " << hcn[2] << ", " << hcn[3] << "]\n";
    }

    return 0;
}
