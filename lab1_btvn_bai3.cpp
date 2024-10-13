#include <bits/stdc++.h>
using namespace std;

class PhanSo {
public:
    long long tu, mau;

    // Ham khoi tao
    PhanSo(long long tu = 0, long long mau = 1) : tu(tu), mau(mau) {
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }

    // Ham nhan hai phan so
    PhanSo operator*(const PhanSo& other) const {
        return PhanSo(tu * other.tu, mau * other.mau);
    }

    // Ham so sanh hai phan so
    bool operator==(const PhanSo& other) const {
        return tu * other.mau == mau * other.tu;
    }

    // Rut gon phan so
    void rutGon() {
        long long gcd = __gcd(tu, mau);
        tu /= gcd;
        mau /= gcd;
    }

    // Ham xuat phan so
    void xuat() const {
        cout << tu << "/" << mau;
    }
};

// Ham so sanh phan so (dung de sap xep)
bool cmp(const PhanSo& a, const PhanSo& b) {
    return a.tu * b.mau < a.mau * b.tu;
}

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    vector<PhanSo> arr(n);
    cout << "Nhap cac phan so (tu va mau tren tung dong):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i].tu >> arr[i].mau;
    }

    long long ak, bk;
    cout << "Nhap phan so dich (tu va mau): ";
    cin >> ak >> bk;
    PhanSo dich(ak, bk);

    PhanSo best;
    vector<PhanSo> bestSubset;
    int minSize = INT_MAX;

    // Duyet tat ca cac tap con
    for (int mask = 1; mask < (1 << n); mask++) {
        PhanSo product(1, 1);
        vector<PhanSo> subset;

        // Tinh tich cua tap con
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                product = product * arr[i];
                subset.push_back(arr[i]);
            }
        }

        // Neu tich bang phan so dich va tap con co kich thuoc nho hon tap con tot nhat hien tai
        if (product == dich && subset.size() < minSize) {
            bestSubset = subset;
            minSize = subset.size();
        }
    }

    // Xuat ket qua
    if (bestSubset.empty()) {
        cout << "Khong co tap con nao thoa man." << endl;
    } else {
        // Sap xep cac phan so trong tap con theo thu tu tu be den lon
        sort(bestSubset.begin(), bestSubset.end(), cmp);

        cout << "Tap con thoa man:\n";
        for (const auto& ps : bestSubset) {
            ps.xuat();
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
