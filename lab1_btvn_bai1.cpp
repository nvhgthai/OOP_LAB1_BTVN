#include <iostream>
using namespace std;

struct PhanSo {
    int tuSo;
    int mauSo;
};

void nhapPhanSo(PhanSo &ps) {
    cout << "Nhap tu so: ";
    cin >> ps.tuSo;
    do {
        cout << "Nhap mau so (khac 0): ";
        cin >> ps.mauSo;
        if (ps.mauSo == 0) {
            cout << "Mau so phai khac 0. Vui long nhap lai.\n";
        }
    } while (ps.mauSo == 0);
}

int soSanhPhanSo(const PhanSo &ps1, const PhanSo &ps2) {
    return ps1.tuSo * ps2.mauSo - ps2.tuSo * ps1.mauSo;
}

void timPhanSoLonNhatVaNhoNhat(PhanSo arr[], int n, PhanSo &phanSoNhoNhat, PhanSo &phanSoLonNhat) {
    phanSoNhoNhat = arr[0];
    phanSoLonNhat = arr[0];
    for (int i = 1; i < n; ++i) {
        if (soSanhPhanSo(arr[i], phanSoNhoNhat) < 0) {
            phanSoNhoNhat = arr[i];
        }
        if (soSanhPhanSo(arr[i], phanSoLonNhat) > 0) {
            phanSoLonNhat = arr[i];
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    PhanSo *arr = new PhanSo[n];

    for (int i = 0; i < n; ++i) {
        cout << "Nhap phan so thu " << i + 1 << ":\n";
        nhapPhanSo(arr[i]);
    }

    PhanSo phanSoNhoNhat, phanSoLonNhat;
    timPhanSoLonNhatVaNhoNhat(arr, n, phanSoNhoNhat, phanSoLonNhat);

    cout << "Phan so nho nhat: " << phanSoNhoNhat.tuSo << "/" << phanSoNhoNhat.mauSo << endl;
    cout << "Phan so lon nhat: " << phanSoLonNhat.tuSo << "/" << phanSoLonNhat.mauSo << endl;

    delete[] arr;
    return 0;
}
