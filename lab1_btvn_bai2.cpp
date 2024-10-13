#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PhanSo {
private:
    int tuSo, mauSo;
public:
    // Constructor
    PhanSo(int tu = 0, int mau = 1) {
        tuSo = tu;
        if (mau == 0) {
            cout << "Mau so phai khac 0. Nhap lai gia tri mau so: ";
            cin >> mauSo;
        } else {
            mauSo = mau;
        }
    }

    // Getter
    int getTuSo() const {
        return tuSo;
    }

    int getMauSo() const {
        return mauSo;
    }

    // Operator overloading for sorting
    bool operator<(const PhanSo &other) const {
        return tuSo * other.mauSo < other.tuSo * mauSo;
    }

    // Nhap phan so
    friend istream &operator>>(istream &is, PhanSo &ps) {
        cout << "Nhap tu so: ";
        is >> ps.tuSo;
        cout << "Nhap mau so: ";
        is >> ps.mauSo;
        while (ps.mauSo == 0) {
            cout << "Mau so phai khac 0. Nhap lai: ";
            is >> ps.mauSo;
        }
        return is;
    }

    // Xuat phan so
    friend ostream &operator<<(ostream &os, const PhanSo &ps) {
        os << ps.tuSo << "/" << ps.mauSo;
        return os;
    }
};

class arrPhanSo {
private:
    vector<PhanSo> arr;
public:
    // Nhap mang phan so
    void nhap(int n) {
        for (int i = 0; i < n; ++i) {
            PhanSo ps;
            cin >> ps;
            arr.push_back(ps);
        }
    }

    // Tim phan so be thu k
    PhanSo phanSoBeThuK(int k) {
        if (k <= 0 || k > arr.size()) {
            cout << "Khong co phan so be thu " << k << endl;
            return PhanSo();
        }
        sort(arr.begin(), arr.end());
        return arr[k - 1];
    }

    // Tim phan so lon thu k
    PhanSo phanSoLonThuK(int k) {
        if (k <= 0 || k > arr.size()) {
            cout << "Khong co phan so lon thu " << k << endl;
            return PhanSo();
        }
        sort(arr.begin(), arr.end());
        return arr[arr.size() - k];
    }
};

int main() {
    int n, k;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    cout << "Nhap gia tri k: ";
    cin >> k;

    arrPhanSo arr;
    arr.nhap(n);

    // Xuat phan so be thu k
    PhanSo beThuK = arr.phanSoBeThuK(k);
    cout << "Phan so be thu " << k << " la: " << beThuK << endl;

    // Xuat phan so lon thu k
    PhanSo lonThuK = arr.phanSoLonThuK(k);
    cout << "Phan so lon thu " << k << " la: " << lonThuK << endl;

    return 0;
}
