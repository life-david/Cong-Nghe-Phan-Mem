#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

// Lop quan ly du lieu thong tin sach
class Sach {
	private:
	    string tieuDe, tacGia, theLoai, nhaXuatBan;
	    double gia;
	    int tonKho;
	public:
	    Sach(string t, string tg, string tl, string nx, double g, int tk) // ham khoi tao
	        : tieuDe(t), tacGia(tg), theLoai(tl), nhaXuatBan(nx), gia(g), tonKho(tk) {} // danh sach khoi tao (gan gia tri vao thuoc tinh)
	
	    string getTieuDe() const { return tieuDe; }   // getter
	    void setTieuDe(string t) { tieuDe = t; }      // setter
	    void setTacGia(string tg) { tacGia = tg; }
	    void setTheLoai(string tl) { theLoai = tl; }
	    void setNhaXuatBan(string nx) { nhaXuatBan = nx; }
	    void setGia(double g) { gia = g; }
	    void setTonKho(int tk) { tonKho = tk; }
	    void thongTinSach() const {
	        cout << "\nTieu de: " << tieuDe << " | Tac gia: " << tacGia
	             << " | The loai: " << theLoai << " | Nha xuat ban: " << nhaXuatBan
	             << " | Gia: " << gia << "VND" << " | Ton kho: " << tonKho << endl;
	    }
	
	    void ghiFile(ofstream &file) const { // ham ghi file
	        file << tieuDe << "," << tacGia << "," << theLoai << ","
	             << nhaXuatBan << "," << gia << "," << tonKho << endl;
	    }
	
	    static Sach docFile(ifstream &file) { // ham doc file (dung ham tinh vi ko can den 1 doi tuong de goi ham)
	        string tieuDe, tacGia, theLoai, nhaXuatBan;
	        double gia;
	        int tonKho;
	        getline(file, tieuDe, ',');
	        getline(file, tacGia, ',');
	        getline(file, theLoai, ',');
	        getline(file, nhaXuatBan, ',');
	        file >> gia;
	        file.ignore(1);
	        file >> tonKho;
	        file.ignore(1);
	        return Sach(tieuDe, tacGia, theLoai, nhaXuatBan, gia, tonKho);
	    }
};

// Lop quan ly du lieu thong tin khach hang
class KhachHang {
	private:
	    string ten, diaChi, soDienThoai;
	public:
	    KhachHang(string t, string dc, string sdt)
	        : ten(t), diaChi(dc), soDienThoai(sdt) {}
	
	    string getTen() const { return ten; }
	    void setTen(string t) { ten = t; }
	    void setDiaChi(string dc) { diaChi = dc; }
	    void setSoDienThoai(string sdt) { soDienThoai = sdt; }
	
	    void thongTinKhachHang() const {
	        cout << "\nTen: " << ten << " | Dia chi: " << diaChi
	             << " | So Dien Thoai: " << soDienThoai << endl;
	    }
	
	    void ghiFile(ofstream &file) const {
	        file << ten << ", " << diaChi << ", " << soDienThoai << endl;
	    }
	
	    static KhachHang docFile(ifstream &file) {
	        string ten, diaChi, soDienThoai;
	        getline(file, ten, ',');
	        getline(file, diaChi, ',');
	        getline(file, soDienThoai);
	        return KhachHang(ten, diaChi, soDienThoai);
	    }
};

// Lop quan ly danh sach cac cuon sach vs cac chuc nang them sua xoa tim
class QuanLySach {
	private:
	    vector<Sach> danhSachSach;
	public:
	    void themSach() { // ham them sach
	        string tieuDe, tacGia, theLoai, nhaXuatBan;
	        double gia;
	        int tonKho;
	        cout << "-Nhap tieu de: ";
	        cin.ignore();
	        getline(cin, tieuDe);
	        cout << "-Nhap tac gia: ";
	        getline(cin, tacGia);
	        cout << "-Nhap the loai: ";
	        getline(cin, theLoai);
	        cout << "-Nhap nha xuat ban: ";
	        getline(cin, nhaXuatBan);
	        cout << "-Nhap gia: ";
	        cin >> gia;
	        cout << "-Nhap so luong ton kho: ";
	        cin >> tonKho;
	        Sach sach(tieuDe, tacGia, theLoai, nhaXuatBan, gia, tonKho);
	        danhSachSach.push_back(sach);
	        cout << "\nTHEM SACH THANH CONG!\n";
	    }
	
	    void suaSach() { // ham sua sach
	        string tieuDe;
	        cout << "-Nhap tieu de sach can sua: ";
	        cin.ignore();
	        getline(cin, tieuDe);
	        int danhdau1=0;
	        for (int i = 0; i < danhSachSach.size(); i++) {
	            if (danhSachSach[i].getTieuDe() == tieuDe) {
	                string tacGia, theLoai, nhaXuatBan;
	                double gia;
	                int tonKho;
	                cout << "-Nhap tac gia moi: ";
	                getline(cin, tacGia);
	                cout << "-Nhap the loai moi: ";
	                getline(cin, theLoai);
	                cout << "-Nhap nha xuat ban moi: ";
	                getline(cin, nhaXuatBan);
	                cout << "-Nhap gia moi: ";
	                cin >> gia;
	                cout << "-Nhap so luong ton kho moi: ";
	                cin >> tonKho;
	                danhSachSach[i].setTacGia(tacGia);
	                danhSachSach[i].setTheLoai(theLoai);
	                danhSachSach[i].setNhaXuatBan(nhaXuatBan);
	                danhSachSach[i].setGia(gia);
	                danhSachSach[i].setTonKho(tonKho);
	                cout << "\nSUA SACH THANH CONG!\n";
					danhdau1=1;
					break;
	            }
	        }
	        if(danhdau1==0){
	            cout << "\nSACH KHONG TIM THAY!\n";
			}
	    }
	    
	    void xoaSach() { // ham xoa sach
	        string tieuDe;
	        cout << "-Nhap tieu de can xoa: ";
	        cin.ignore();
	        getline(cin, tieuDe);
	        int danhdau2=0;
	        for (int i = 0; i < danhSachSach.size(); i++) {
	            if (danhSachSach[i].getTieuDe() == tieuDe) {
	                danhSachSach.erase(danhSachSach.begin() + i);
	                cout << "\nXOA SACH THANH CONG!\n";
	                danhdau2=1;
	                break;
	            }
	        }
	        if(danhdau2==0){
	        	cout << "\nSACH KHONG TIM THAY!\n";
			}
	    }
	
	    void timSach() { // ham tim sach
	        string tieuDe;
	        cout << "-Nhap tieu de can tim: ";
	        cin.ignore();
	        getline(cin, tieuDe);
	        int danhdau3=0;
	        for (int i = 0; i < danhSachSach.size(); i++) {
	            if (danhSachSach[i].getTieuDe() == tieuDe) {
	                danhSachSach[i].thongTinSach();
	                danhdau3=1;
	                break;
	            }
	        }
	        if(danhdau3==0){
	            cout << "\nSACH KHONG TIM THAY!\n";
			}
	    }
	
	    void ghiFile() const { // ham ghi file
	        ofstream file("sach.txt");
	        file << danhSachSach.size() << endl;
	        for (int i=0; i <danhSachSach.size();i++) {
	            danhSachSach[i].ghiFile(file);
	        }
	        file.close();
	    }
	
	    void docFile() { // ham doc file
	        ifstream file("sach.txt");
	        if (file.is_open()) {
	            danhSachSach.clear();
	            int soLuong;
	            file >> soLuong;
	            file.ignore(1);
	            for (int i = 0; i < soLuong; ++i) {
	                danhSachSach.push_back(Sach::docFile(file));
	            }
	            file.close();
	        } else {
	            cout << "Khong the mo file de doc!\n";
	        }
	    }
};

// Lop quan ly khach hang voi cac chuc nang them sua xoa tim
class QuanLyKhachHang {
private:
    vector<KhachHang> danhSachKhachHang;
public:
    void themKhachHang() { // ham them khach hang
        string ten, diaChi, soDienThoai;
        cout << "-Nhap ten: ";
        cin.ignore();
        getline(cin, ten);
        cout << "-Nhap dia chi: ";
        getline(cin, diaChi);
        cout << "-Nhap so dien thoai: ";
        getline(cin, soDienThoai);
        KhachHang khachHang(ten, diaChi, soDienThoai);
        danhSachKhachHang.push_back(khachHang);
        cout << "\nTHEM KHACH HANG THANH CONG!\n";
    }

    void suaKhachHang() { // ham sua khach hang
        string ten;
        cout << "-Nhap ten cua khach hang can sua: ";
        cin.ignore();
        getline(cin, ten);
        int danhdau4=0;
        for (int i = 0; i < danhSachKhachHang.size(); i++) {
            if (danhSachKhachHang[i].getTen() == ten) {
                string diaChi, soDienThoai;
                cout << "-Nhap dia chi moi: ";
                getline(cin, diaChi);
                cout << "-Nhap so dien thoai moi: ";
                getline(cin, soDienThoai);
                danhSachKhachHang[i].setDiaChi(diaChi);
                danhSachKhachHang[i].setSoDienThoai(soDienThoai);
                cout << "\nSUA KHACH HANG THANH CONG!\n";
				danhdau4=1;
				break;
            }
        }
        if(danhdau4=0){
            cout << "\nKHACH HANG KHONG TIM THAY!\n";	
		}
    }

    void xoaKhachHang() { // ham xoa khach hang
        string ten;
        cout << "-Nhap ten cua khach hang can xoa: ";
        cin.ignore();
        getline(cin, ten);
        int danhdau5=0;
        for (int i = 0; i < danhSachKhachHang.size(); i++) {
            if (danhSachKhachHang[i].getTen() == ten) {
                danhSachKhachHang.erase(danhSachKhachHang.begin() + i);
                cout << "\nXOA KHACH HANG THANH CONG!\n";
                danhdau5=1;
                break;
            }
        }
        if(danhdau5==0){
        	cout << "\nKHACH HANG KHONG TIM THAY!\n";
		}
    }

    void timKhachHang() { // ham tim khach hang
        string ten;
        cout << "-Nhap ten cua khach hang can tim: ";
        cin.ignore();
        getline(cin, ten);
        int danhdau6=0;
        for (int i = 0; i < danhSachKhachHang.size(); i++) {
            if (danhSachKhachHang[i].getTen() == ten) {
                danhSachKhachHang[i].thongTinKhachHang();
                danhdau6=1;
                break;
            }
        }
        if(danhdau6==0){
            cout << "\nKHACH HANG KHONG TIM THAY!\n";
		}
    }

    void ghiFile() const { // ham ghi file
        ofstream file("khachhang.txt");
        file << danhSachKhachHang.size() << endl;
        for (int i=0; i< danhSachKhachHang.size();i++) {
            danhSachKhachHang[i].ghiFile(file);
        }
        file.close();
    }

    void docFile() { // ham doc file
        ifstream file("khachhang.txt");
        if (file.is_open()) {
            danhSachKhachHang.clear();
            int soLuong;
            file >> soLuong;
            file.ignore(1);
            for (int i = 0; i < soLuong; ++i) {
                danhSachKhachHang.push_back(KhachHang::docFile(file));
            }
            file.close();
        } else {
            cout << "Khong the mo file de doc!\n";
        }
    }
};

// Cau truc don hang
struct donhang {
    int ma;              
    string tensach;     
    string tenkhach;  
    string ngay;      
};

// Cau truc thong tin sach
struct thongtinsach {
    string theloai;    
    string tacgia;      
};

// Lop quan ly don hang
class quanlydonhang {
    vector<donhang> danhsach;   
public:
    quanlydonhang() {
        doctufile();    
    }

    void taodon(int ma, string tensach, string tenkhach, string ngay) {
        for (size_t i = 0; i < danhsach.size(); ++i) {
            if (danhsach[i].ma == ma) {
                cout << "\nDA TON TAI DON HANG CO MA NAY." << endl;
                return;  
            }
        }
        donhang don = {ma, tensach, tenkhach, ngay};
        danhsach.push_back(don);
        ghirafile();   
    }

    void xemlichsu() const {
        for (size_t i = 0; i < danhsach.size(); ++i) {
            cout << "\n Ma don hang: " << danhsach[i].ma
                 << " | Ten sach: " << danhsach[i].tensach
                 << " | Khach hang: " << danhsach[i].tenkhach
                 << " | Ngay: " << danhsach[i].ngay << endl;
        }
    }

    void lietkedonhangcungngay(string ngay) const {
        bool found = false;
        for (size_t i = 0; i < danhsach.size(); ++i) {
            if (danhsach[i].ngay == ngay) {
                cout << "\n Ma don hang: " << danhsach[i].ma
                     << " | Ten sach: " << danhsach[i].tensach
                     << " | Khach hang: " << danhsach[i].tenkhach
                     << " | Ngay: " << danhsach[i].ngay << endl;
                found = true;
            }
        }
        if (!found) cout << "\nKHONG CO DON HANG NAO CO NGAY: " << ngay << endl;
    }

    void lietkedonhangcungkhachhang(string tenkhach) const {
        bool found = false;
        for (size_t i = 0; i < danhsach.size(); ++i) {
            if (danhsach[i].tenkhach == tenkhach) {
                cout << "\n Ma don hang: " << danhsach[i].ma
                     << " | Ten sach: " << danhsach[i].tensach
                     << " | Khach hang: " << danhsach[i].tenkhach
                     << " | Ngay: " << danhsach[i].ngay << endl;
                found = true;
            }
        }
        if (!found) cout << "\nKHONG CO DON HANG NAO CUA KHACH HANG: " << tenkhach << endl;
    }

    void xoahetdonhang() {
        danhsach.clear();
        ghirafile();   
        cout << "\nDA XOA HET CAC DON HANG." << endl;
    }

    void xoadonhang(int ma) {
        for (size_t i = 0; i < danhsach.size(); ++i) {
            if (danhsach[i].ma == ma) {
                danhsach.erase(danhsach.begin() + i);
                ghirafile();   
                cout << "\nDA XOA DON HANG CO MA SO: " << ma << "." << endl;
                return;
            }
        }
        cout << "\nKHONG TIM THAY DON HANG CO MA SO: " << ma << "." << endl;
    }

private:
	void doctufile() {
        ifstream file("donhang.txt");
        if (file.is_open()) {
            donhang don;
            while (file >> don.ma) {
                file.ignore();
                getline(file, don.tensach);
                getline(file, don.tenkhach);
                getline(file, don.ngay);
                danhsach.push_back(don);
            }
            file.close();
        }
    }

    void ghirafile() const {
        ofstream file("donhang.txt");
        if (file.is_open()) {
            for (size_t i = 0; i < danhsach.size(); ++i) {
                file << danhsach[i].ma << endl
                     << danhsach[i].tensach << endl
                     << danhsach[i].tenkhach << endl
                     << danhsach[i].ngay << endl;
            }
            file.close();
        }
    }
};

// Lop quan ly the loai va tac gia
class quanlytheloaitacgia {
    map<string, thongtinsach> sach;  
public:
    quanlytheloaitacgia() {
        doctufile();   
    }

    void themsach(string tieude, string theloai, string tacgia) {
        if (sach.find(tieude) != sach.end()) {
            cout << "\nDA TON TAI TIEU DE NAY." << endl;
            return;
        }
        thongtinsach thongtin = {theloai, tacgia};
        sach[tieude] = thongtin;
        ghirafile();    
    }

    void xemsach() const {
        for (map<string, thongtinsach>::const_iterator it = sach.begin(); it != sach.end(); ++it) {
            cout << "\nTieu de: " << it->first
                 << " | The loai: " << it->second.theloai
                 << " | Tac gia: " << it->second.tacgia << endl;
        }
    }

    void lietkecungtacgia(string tacgia) const {
        bool found = false;
        for (map<string, thongtinsach>::const_iterator it = sach.begin(); it != sach.end(); ++it) {
            if (it->second.tacgia == tacgia) {
                cout << "\nTieu de: " << it->first
                     << " | The loai: " << it->second.theloai
                     << " | Tac gia: " << it->second.tacgia << endl;
                found = true;
            }
        }
        if (!found) cout << "\nKhong co sach nao cua tac gia " << tacgia << endl;
    }

    void lietkecungtheloai(string theloai) const {
        bool found = false;
        for (map<string, thongtinsach>::const_iterator it = sach.begin(); it != sach.end(); ++it) {
            if (it->second.theloai == theloai) {
                cout << "\n Tieu de: " << it->first
                     << " | The loai: " << it->second.theloai
                     << " | Tac gia: " << it->second.tacgia << endl;
                found = true;
            }
        }
        if (!found) cout << "\nKhong co sach nao thuoc the loai " << theloai << endl;
    }

    void xoahetsach() {
        sach.clear();
        ghirafile();   
        cout << "\nDA XOA HET SACH." << endl;
    }

private:
    void doctufile() {
        ifstream file("theloaitacgia.txt");
        if (file.is_open()) {
        	string tieude;
            thongtinsach thongtin;
            while (getline(file, tieude)) {
                getline(file, thongtin.theloai);
                getline(file, thongtin.tacgia);
                sach[tieude] = thongtin;
            }
            file.close();
        }
    }

    void ghirafile() const {
        ofstream file("theloaitacgia.txt");
        if (file.is_open()) {
            for (map<string, thongtinsach>::const_iterator it = sach.begin(); it != sach.end(); ++it) {
                file << it->first << endl
                     << it->second.theloai << endl
                     << it->second.tacgia << endl;
            }
            file.close();
        }
    }
};

// Ham quan ly menu don hang
void menuquanlydonhang(quanlydonhang &qldonhang) {
    int chon;
    while (true) {
        cout<<"\t\t\t---------------------------------------------"<<endl;
    	cout<<"\t\t\t|             QUAN LY DON HANG              |"<<endl;
    	cout<<"\t\t\t---------------------------------------------"<<endl;
        cout << "\t\t\t1. Tao don hang" << endl;
		cout << "\t\t\t2. Xem lich su don hang " << endl;
		cout << "\t\t\t3. Liet ke don hang cung ngay " << endl;
		cout << "\t\t\t4. Liet ke don hang cung khach hang" << endl;
		cout << "\t\t\t5. Xoa het don hang" << endl;
		cout << "\t\t\t6. Xoa don hang theo ma" << endl;
		cout << "\t\t\t7. Quay lai" << endl;
		cout << "Nhap lua chon cua ban: ";
        cin >> chon;
        if (chon == 1) {
            int ma;
            string tensach, tenkhach, ngay;
            cout << "-Nhap ma don hang: ";
            cin >> ma;
            cin.ignore();
            cout << "-Ten sach: ";
            getline(cin, tensach);
            cout << "-Ten khach hang: ";
            getline(cin, tenkhach);
            cout << "-Ngay: ";
            getline(cin, ngay);
            qldonhang.taodon(ma, tensach, tenkhach, ngay);
        } else if (chon == 2) {
            qldonhang.xemlichsu();
        } else if (chon == 3) {
            string ngay;
            cout << "-Nhap ngay: ";
            cin >> ngay;
            qldonhang.lietkedonhangcungngay(ngay);
        } else if (chon == 4) {
            string tenkhach;
            cout << "-Nhap ten khach hang: ";
            cin.ignore();
            getline(cin, tenkhach);
            qldonhang.lietkedonhangcungkhachhang(tenkhach);
        } else if (chon == 5) {
            qldonhang.xoahetdonhang();
        } else if (chon == 6) {
            int ma;
            cout << "-Nhap ma don hang: ";
            cin >> ma;
            qldonhang.xoadonhang(ma);
        } else if (chon == 7) {
            break;
        }
    }
}

// Ham quan ly menu sach
void menuquanlytheloaitacgia(quanlytheloaitacgia &qltheloaitacgia) {
    int chon;
    while (true) {
        cout<<"\t\t\t---------------------------------------------"<<endl;
    	cout<<"\t\t\t|        QUAN LY THE LOAI VA TAC GIA        |"<<endl;
    	cout<<"\t\t\t---------------------------------------------"<<endl;
        cout << "\t\t\t1. Them sach" << endl;
        cout << "\t\t\t2. Xem sach" << endl;
        cout << "\t\t\t3. Liet ke sach cung tac gia" << endl;
        cout << "\t\t\t4. Liet ke sach cung the loai" << endl;
        cout << "\t\t\t5. Xoa het sach" << endl;
        cout << "\t\t\t6. Quay lai" << endl;
		cout << "Nhap lua chon cua ban: ";
        cin >> chon;
        if (chon == 1) {
            string tieude, theloai, tacgia;
            cout << "\n-Nhap tieu de sach: ";
            cin.ignore();
            getline(cin, tieude);
            cout << "-Nhap the loai: ";
            getline(cin, theloai);
            cout << "-Nhap tac gia: ";
            getline(cin, tacgia);
            qltheloaitacgia.themsach(tieude, theloai, tacgia);
        } else if (chon == 2) {
            qltheloaitacgia.xemsach();
        } else if (chon == 3) {
            string tacgia;
            cout << "-Nhap tac gia: ";
            cin.ignore();
            getline(cin, tacgia);
            qltheloaitacgia.lietkecungtacgia(tacgia);
        } else if (chon == 4) {
            string theloai;
            cout << "-Nhap the loai: ";
            cin.ignore();
            getline(cin, theloai);
            qltheloaitacgia.lietkecungtheloai(theloai);
        } else if (chon == 5) {
            qltheloaitacgia.xoahetsach();
        } else if (chon == 6) {
            break;
        }
    }
}

class ThuVien {
    private:
        string hoten, maso, diachi, email, sodienthoai, xephang, binhluan ,motakhuyenmai, tylegiamgia , thoigianapdung ;
    public:
        void menu();
        void them();
        void hienThi();
        void chinhSua();
        void timKiem();
        void xoa();
        void danhgia(); 
        void khuyenmai();
        void hienthidanhgia();
        void hienthikhuyenmai();
        void xoakhuyenmai();
};

void ThuVien::menu() {
menustart:
    int luaChon;
    char x;
    system("cls");

    cout<<"\t\t\t---------------------------------------------"<<endl;
    cout<<"\t\t\t| HE THONG QUAN LY NHA XUAT BAN VA DANH GIA |"<<endl;
    cout<<"\t\t\t---------------------------------------------"<<endl;
    cout<<"\t\t\t 1. Them Nha Xuat Ban"<<endl;
    cout<<"\t\t\t 2. Hien Thi Nha Xuat Ban"<<endl;
    cout<<"\t\t\t 3. Chinh Sua Nha Xuat Ban "<<endl;
    cout<<"\t\t\t 4. Tim Kiem Nha Xuat Ban "<<endl;
    cout<<"\t\t\t 5. Xoa Nha Xuat Ban "<<endl;
    cout<<"\t\t\t 6. Danh Gia Nha Xuat Ban "<<endl;
    cout<<"\t\t\t 7. Them khuyen Mai "<<endl;
    cout<<"\t\t\t 8. Hien Thi Danh Gia Nha Xuat Ban "<<endl;
    cout<<"\t\t\t 9. Hien Thi Khuyen Mai "<<endl;
    cout<<"\t\t\t 10. Xoa Khuyen Mai "<<endl;
    cout<<"\t\t\t 11. Thoat"<<endl;

    cout<<"\t\t\t---------------------------------------"<<endl;
    cout<<"\t\t\tChon Lua Chon:[1/2/3/4/5/6/7/8/9/10/11]"<<endl;
    cout<<"\t\t\t---------------------------------------"<<endl;
    cout<<"Nhap Lua Chon: ";
    cin >> luaChon;

    switch (luaChon) {
        case 1:
            do {
                them();
                cout << "\n\t\t\t Them Nha Xuat Ban Khac (Y,N): ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            getch();
    		goto menustart;
            break;
        case 2:
            hienThi();
            getch();
    		goto menustart;
            break;
        case 3:
            chinhSua();
            getch();
    		goto menustart;
            break;
        case 4:
            timKiem();
            getch();
    		goto menustart;
            break;
        case 5:
            xoa();
            getch();
    		goto menustart;
            break;
        case 6:
            danhgia();
            getch();
    		goto menustart;
            break;
        case 7:
        	khuyenmai();
        	getch();
    		goto menustart;
        	break;
        case 8:
        	hienthidanhgia();
        	getch();
    		goto menustart;
        	break;
        case 9:
        	hienthikhuyenmai();
        	getch();
    		goto menustart;
        	break;
        case 10:
			xoakhuyenmai(); 
			getch();
   			goto menustart;
       		break;
        case 11:
  			break;
  			
        default:
            cout << "\n\t\t\t Lua chon khong hop le... vui long thu lai.."; break;
    } while(luaChon!=11);
}

void ThuVien::them() {
    system("cls");
    fstream file;
    cout << "\n--------------------------------------------------------------------------------------------------------------";
    cout << "\n---------------------------------------- Them Thong Tin Nha Xuat Ban -----------------------------------------" << endl;
    cout << "\t\t\tNhap Ten Nha Xuat Ban: ";
    cin >> hoten;
    cout << "\t\t\tNhap Ma So: ";
    cin >> maso;
    cout << "\t\t\tNhap Email: ";
    cin >> email;
    cout << "\t\t\tNhap So Dien Thoai: ";
    cin >> sodienthoai;
    cout << "\t\t\tNhap Dia Chi: ";
    cin >> diachi;

    file.open("ThuVien.txt", ios::app | ios::out);
    file << " " << hoten << " " << maso << " "  << email << " " << sodienthoai << " " << diachi << "\n";
    file.close();
}

void ThuVien::hienThi() {
    system("cls");
    fstream file;
    int tong = 0;
    cout << "\n--------------------------------------------------------------------------------------------------------" << endl;
    cout << "----------------------------------------  Thong Tin Nha Xuat Ban -----------------------------------------" << endl;
    file.open("ThuVien.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\tKhong co du lieu...";
        file.close();
    } else {
        file >> hoten >> maso >> email >> sodienthoai >> diachi;
        while (!file.eof()) {
            cout << "\n\n\t\t\t Nha Xuat Ban: " << tong++ << endl;
            cout << "\t\t\t Ho Ten: " << hoten << endl;
            cout << "\t\t\t Ma So Nha Xuat Ban: " << maso << endl;
            cout << "\t\t\t So Dien Thoai: " << sodienthoai << endl;
            cout << "\t\t\t Email: " << email << endl;
            cout << "\t\t\t Dia Chi: " << diachi << endl;
            file >> hoten >> maso >> email >> sodienthoai >> diachi;
        }
        if (tong == 0) {
            cout << "\n\t\t\tKhong co du lieu...";
        }
    }
    file.close();
}

void ThuVien::chinhSua() {
    system("cls");
    fstream file, fileTam;
    int timthay = 0;
    string masocantim;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "---------------------------------------- Chinh Sua Thong Nha Xuat Ban -----------------------------------------" << endl;
    file.open("ThuVien.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\tKhong co du lieu...";
    } else {
        cout << "\n Nhap Ma So Nha Xuat Ban muon chinh sua: ";
        cin >> masocantim;
        fileTam.open("tam.txt", ios::app | ios::out);
        file >> hoten >> maso >> email >> sodienthoai >> diachi;
        while (!file.eof()) {
            if (masocantim != maso) {
                fileTam << " " << hoten << " " << maso << " " << email << " " << sodienthoai << " " << diachi << "\n";
            } else {
                cout << "\t\t\tNhap Ten Nha Xuat Ban : ";
                cin >> hoten;
                cout << "\t\t\tNhap Ma So: ";
                cin >> maso;
                cout << "\t\t\tNhap Email: ";
                cin >> email;
                cout << "\t\t\tNhap So Dien Thoai: ";
                cin >> sodienthoai;
                cout << "\t\t\tNhap Dia Chi: ";
                cin >> diachi;
                fileTam << " " << hoten << " " << maso << " "<< email << " " << sodienthoai << " " << diachi << "\n";
                timthay++;
            }
            file >> hoten >> maso >> email >> sodienthoai >> diachi;
        }
        if (timthay == 0) {
            cout << "\n\t\t\tKhong tim thay Ma So Nha Xuat Ban...";
        } 
        fileTam.close();
        file.close();
        remove("ThuVien.txt");
        rename("tam.txt", "ThuVien.txt");
    }
}

void ThuVien::timKiem() {
    system("cls");
    fstream file;
    int timthay = 0;
    file.open("ThuVien.txt", ios::in);
    if (!file) {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "---------------------------------------- Tim Kiem Thong Tin Nha Xuat Ban  -----------------------------------------" << endl;
        cout << "\n\t\t\tKhong co du lieu...";
    } else {
        string masocantim;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "---------------------------------------- Tim Kiem Thong Tin Nha Xuat Ban -----------------------------------------" << endl;
        cout << "\n Nhap Ma So Nha Xuat Ban can tim: ";
        cin >> masocantim;
        file >> hoten >> maso >> email >> sodienthoai >> diachi;
        while (!file.eof()) {
            if (masocantim == maso) {
                cout << "\t\t\t Ho Ten: " << hoten << endl;
                cout << "\t\t\t Ma So Nha xuat Ban: " << maso << endl;
                cout << "\t\t\t Email: " << email << endl;
                cout << "\t\t\t Dia Chi: " << diachi << endl;
                timthay++;
            }
            file >> hoten >> maso >> email >> sodienthoai >> diachi;
        }
        if (timthay == 0) {
            cout << "\n\t\t\t Khong tim thay Ma So Nha Xuat Ban...";
        }
        file.close();
    }
}

void ThuVien::xoa() {
    system("cls");
    fstream file, fileTam;
    string masocanxoa;
    int timthay = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "---------------------------------------- Xoa Thong Tin Nha Xuat Ban -----------------------------------------" << endl;
    file.open("ThuVien.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\tKhong co du lieu...";
    } else {
        cout << "\n Nhap Ma So Nha Xuat Ban can xoa: ";
        cin >> masocanxoa;
        fileTam.open("tam.txt", ios::app | ios::out);
        file >> hoten >> maso >> email >> sodienthoai >> diachi;
        while (!file.eof()) {
            if (masocanxoa != maso) {
                fileTam << " " << hoten << " " << maso << " " << email << " " << sodienthoai << " " << diachi << "\n";
            }
            file >> hoten >> maso >> email >> sodienthoai >> diachi;
        }
        if (timthay == 0) {
            cout << "\n\t\t\t Khong tim thay Ma So Nha Xuat Ban...";
        }
        fileTam.close();
        file.close();
        remove("ThuVien.txt");
        rename("tam.txt", "ThuVien.txt");
    }
}

void ThuVien::danhgia() {
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------";
    cout << "\n---------------------------------------- Them Danh Gia -----------------------------------------" << endl;
    cout << "\t\t\tNhap Ma So Nha Xuat Ban: ";
    cin >> maso;
    cout << "\t\t\tNhap Xep Hang (1-5): ";
    cin >> xephang;
    cout << "\t\t\tNhap Binh Luan: ";
    cin.ignore();
    getline(cin, binhluan);

    file.open("DanhGia.txt", ios::app | ios::out);
    file << " " << maso << " " << xephang << " " << binhluan << "\n";
    file.close();
}

void ThuVien::khuyenmai() {
    system("cls");
    fstream file;

    string maso, motakhuyenmai, thoigianapdung;
    int tylegiamgia;

    cout << "\n---------------------------------------- Them Khuyen Mai -----------------------------------------" << endl;

    cout << "\nNhap Ma So Nha Xuat Ban: ";
    cin >> maso;
    cin.ignore();  

    cout << "\nNhap Mo Ta Khuyen Mai: ";
    getline(cin, motakhuyenmai);

    cout << "\nNhap Ty Le Giam Gia (%): ";
    cin >> tylegiamgia;
    cin.ignore();  

    cout << "\nNhap Thoi Gian Ap Dung: ";
    getline(cin, thoigianapdung);

    
    file.open("KhuyenMai.txt", ios::app);
    if (!file) {
        cout << "\n\t\t\tKhong the mo file de ghi du lieu!";
        return;
    }

    file << maso << " " << motakhuyenmai << "|" << tylegiamgia << " " << thoigianapdung << "\n";
    file.close();

    cout << "\n\t\t\tDa them khuyen mai thanh cong!";
}



void ThuVien::hienthidanhgia() {
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------";
    cout << "\n---------------------------------------- Hien Thi Danh Gia -----------------------------------------" << endl;
    file.open("DanhGia.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\tKhong co du lieu danh gia...";
    } else {
        while (file >> maso >> xephang) {
            getline(file, binhluan);
            cout << "\n Ma So NXB: " << maso;
            cout << "\n Xep Hang: " << xephang;
            cout << "\n Binh Luan: " << binhluan << "\n";
        }
    }
    file.close();
}


void ThuVien::hienthikhuyenmai() {
    system("cls");
    fstream file;

    cout << "\n-------------------------------------------------------------------------------------------------------";
    cout << "\n---------------------------------------- Hien Thi Khuyen Mai -----------------------------------------" << endl;

    file.open("KhuyenMai.txt", ios::in);

    if (!file) {
        cout << "\n\t\t\tKhong co du lieu khuyen mai...";
        return;
    }

    cout << "\n\t\t\tDanh sach khuyen mai:\n";
    cout << "\t\t\t--------------------------------------------------\n";

    string line;  
    while (getline(file, line)) {  
        stringstream ss(line); 

        ss >> maso;
        ss.ignore();  
        getline(ss, motakhuyenmai, '|');  
        ss >> tylegiamgia;
        ss.ignore();  
        getline(ss, thoigianapdung);  

        cout << "\n\tMa So Nha Xuat Ban: " << maso;
        cout << "\n\tMo Ta Khuyen Mai: " << motakhuyenmai;
        cout << "\n\tTy Le Giam Gia: " << tylegiamgia << "%";
        cout << "\n\tThoi Gian Ap Dung: " << thoigianapdung << "\n";
    }

    file.close();
}



void ThuVien::xoakhuyenmai() {
    system("cls");
    fstream file, fileTam;
    string masocantim;
    int timthay = 0;

    cout << "\n---------------------------------------- Xoa Khuyen Mai -----------------------------------------" << endl;
    cout << "\n Nhap Ma So Nha Xuat Ban muon xoa khuyen mai: ";
    cin >> masocantim;

    file.open("KhuyenMai.txt", ios::in);
    fileTam.open("tam.txt", ios::out);

    if (!file) {
        cout << "\n\t\t\tKhong co du lieu khuyen mai...";
        return;
    }

    if (!fileTam) {
        cout << "\n\t\t\tKhong the mo file tam de ghi du lieu!";
        file.close();
        return;
    }

    while (file >> maso) {
        file.ignore();
        getline(file, motakhuyenmai, '|'); 
        file >> tylegiamgia;
        file.ignore();
        getline(file, thoigianapdung);

        if (maso != masocantim) {
            fileTam << maso << " " << motakhuyenmai << "|" << tylegiamgia << " " << thoigianapdung << "\n";
        } else {
            timthay = 1; // ��nh d?u t?m th?y m? c?n x�a
        }
    }

    if (timthay == 0) {
        cout << "\n\t\t\tKhong tim thay Ma So Nha Xuat Ban can xoa...";
    } else {
        cout << "\n\t\t\tDa xoa thanh cong!";
    }

    file.close();
    fileTam.close();

    remove("KhuyenMai.txt");
    rename("tam.txt", "KhuyenMai.txt");
}

// Lop quan ly cac du lieu thong tin nhan vien
class nhanvien {
private:
    string ten;
    string vaiTro;
    double luong;
    int doanhSoBanHang;

public:
    nhanvien(string t = "", string vt = "", double lg = 0.0, int ds = 0) {
        ten = t;
        vaiTro = vt;
        luong = lg;
        doanhSoBanHang = ds;
    }

    void nhapThongTin() {
        cout << "Nhap Ten: ";
        getline(cin, ten);
        cout << "Nhap Vai Tro: ";
        getline(cin, vaiTro);
        cout << "Nhap Luong: ";
        cin >> luong;
        cout << "Nhap Doanh So Ban Hang: ";
        cin >> doanhSoBanHang;
        cin.ignore();
    }

    void hienThiThongTin() const {
        cout << "\nTen: " << ten << " | Vai Tro: " << vaiTro
             << " | Luong: " << luong << "kVND" << " | Doanh So: " << doanhSoBanHang << endl;
    }

    string getTen() const { return ten; }
    string getVaiTro() const { return vaiTro; }
    double getLuong() const { return luong; }
    int getDoanhSoBanHang() const { return doanhSoBanHang; }

    void setTen(const string &t) { ten = t; }
    void setVaiTro(const string &vt) { vaiTro = vt; }
    void setLuong(double lg) { luong = lg; }
    void setDoanhSoBanHang(int ds) { doanhSoBanHang = ds; }
};

// Lop quan ly nhan vien
class quanlynv {
private:
    vector<nhanvien> danhSachNhanVien;

public:
    void themNhanVien() {
        nhanvien nv;
        nv.nhapThongTin();
        danhSachNhanVien.push_back(nv);
        cout << "\nDA THEM NHAN VIEN.\n";
    }

    void hienThiDanhSach() const {
        cout << "\nDANH SACH NHAN VIEN" << endl;
        for (size_t i = 0; i < danhSachNhanVien.size(); i++) {
            danhSachNhanVien[i].hienThiThongTin();
        }
    }

    void suaThongTinNhanVien(const string &ten) {
        for (size_t i = 0; i < danhSachNhanVien.size(); ++i) {
            if (danhSachNhanVien[i].getTen() == ten) {
                cout << "Nhap Thong Tin Moi Cho Nhan Vien " << ten << ":\n";
                danhSachNhanVien[i].nhapThongTin();
                cout << "\nDA SUA THONG TIN NHAN VIEN.\n";
                return;
            }
        }
        cout << "\nKHONG TIM THAY NHAN VIEN NAO CO TEN: " << ten << ".\n";
    }

    void xoaNhanVien(const string &ten) {
        for (size_t i = 0; i < danhSachNhanVien.size(); ++i) {
            if (danhSachNhanVien[i].getTen() == ten) {
                danhSachNhanVien.erase(danhSachNhanVien.begin() + i);
                cout << "\nDA XOA NHAN VIEN: " << ten << ".\n";
                return;
            }
        }
        cout << "\nKHONG TIM THAY NHAN VIEN CO TEN: " << ten << ".\n";
    }

    void timKiemNhanVien(const string &ten) const {
        for (size_t i = 0; i < danhSachNhanVien.size(); ++i) {
            if (danhSachNhanVien[i].getTen() == ten) {
                danhSachNhanVien[i].hienThiThongTin();
                return;
            }
        }
        cout << "\nKHONG TIM THAY NHAN VIEN CO TEN: " << ten << ".\n";
    }

    void ghiFile() const {
        ofstream file("nhanvien.txt");
        if (!file) {
            cout << "Khong Mo Duoc Tep nhanvien.txt De Ghi.\n";
            return;
        }
        for (size_t i = 0; i < danhSachNhanVien.size(); ++i) {
            file << danhSachNhanVien[i].getTen() << " " 
                 << danhSachNhanVien[i].getVaiTro() << " "
                 << danhSachNhanVien[i].getLuong() << " " 
                 << danhSachNhanVien[i].getDoanhSoBanHang() << endl;
        }
        file.close();
    }
    void docFile() {
        ifstream file("nhanvien.txt");
        if (!file) {
            cout << "Khong Mo Duoc Tep nhanvien.txt.\n";
            return;
        }
        string ten, vaiTro;
        double luong;
        int doanhSo;
        while (file >> ten >> vaiTro >> luong >> doanhSo) {
            danhSachNhanVien.push_back(nhanvien(ten, vaiTro, luong, doanhSo));
        }
        file.close();
    }
};

// Lop quan ly bao cao
class quanlybc {
private:
    double tongDoanhThu;
    int tongDonHang;
    int tongSoLuongBan;

public:
    quanlybc() : tongDoanhThu(0), tongDonHang(0), tongSoLuongBan(0) {}

    void taoBaoCao() {
        double doanhThu;
        int soLuong;
        cout << "Nhap Doanh Thu: ";
        cin >> doanhThu;
        cout << "Nhap So Luong Ban: ";
        cin >> soLuong;
        cin.ignore();
        tongDoanhThu += doanhThu;
        tongDonHang++;
        tongSoLuongBan += soLuong;
        cout << "\nDA TAO BAO CAO.\n";
    }

    void hienThiBaoCao() const {
        cout << "\nTong Doanh Thu: " << tongDoanhThu << " kVND\n";
        cout << "\nTong So Don Hang: " << tongDonHang << "\n";
        cout << "\nTong So Luong Ban: " << tongSoLuongBan << "\n";
    }

    void ghiFile() const {
        ofstream file("baocao.txt");
        if (!file) {
            cout << "Khong Mo Duoc Tep baocao.txt De Ghi.\n";
            return;
        }
        file << tongDoanhThu << " " << tongDonHang << " " << tongSoLuongBan << endl;
        file.close();
    }

    void docFile() {
        ifstream file("baocao.txt");
        if (!file) {
            cout << "Khong mo duoc tep baocao.txt.\n";
            return;
        }
        file >> tongDoanhThu >> tongDonHang >> tongSoLuongBan;
        file.close();
    }
};

int main(){
	QuanLySach quanLySach;
    QuanLyKhachHang quanLyKhachHang;
    quanLySach.docFile();
    quanLyKhachHang.docFile();
    quanlydonhang qldonhang;
    quanlytheloaitacgia qltheloaitacgia;
    quanlynv qlNhanVien;
    quanlybc qlBaoCao;
    qlNhanVien.docFile();
    qlBaoCao.docFile();
    ThuVien duan;
    int luaChon;
    do {
    	cout << "\t\t\t-----------------------------------------------" << endl;
    	cout << "\t\t\t|              QUAN LY HIEU SACH              |" << endl;
    	cout << "\t\t\t-----------------------------------------------" << endl;
        cout << "\t\t\t1. Quan ly sach" << endl;
        cout << "\t\t\t2. Quan ly khach hang" << endl;
        cout << "\t\t\t3. Quan ly don hang" << endl;
        cout << "\t\t\t4. Quan ly the loai va tac gia" << endl;
        cout << "\t\t\t5. Quan ly nha xuat ban, danh gia va khuyen mai" << endl;
        cout << "\t\t\t6. Quan ly nhan vien" << endl;
        cout << "\t\t\t7. Quan ly bao cao doanh thu" << endl;
        cout << "\t\t\t8. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        switch (luaChon) {
            case 1: {
                int luaChonSach;
                do {
                	cout << endl;
                	cout << "\t\t\t-----------------------------------------------" << endl;
                    cout << "\t\t\t|                  QUAN LY SACH               |" << endl;
                    cout << "\t\t\t-----------------------------------------------" << endl;
                    cout << "\t\t\t1. Them sach" << endl;
                    cout << "\t\t\t2. Sua sach" << endl;
                    cout << "\t\t\t3. Xoa sach" << endl;
                    cout << "\t\t\t4. Tim sach" << endl;
                    cout << "\t\t\t5. Quay lai" << endl;
                    cout << "Nhap lua chon cua ban: ";
                    cin >> luaChonSach;
                    switch (luaChonSach) {
                        case 1: quanLySach.themSach(); break;
                        case 2: quanLySach.suaSach(); break;
                        case 3: quanLySach.xoaSach(); break;
                        case 4: quanLySach.timSach(); break;
                        case 5: break;
                        default: cout << "Lua chon khong hop le!\n"; break;
                    }
                } while (luaChonSach != 5);
                quanLySach.ghiFile();
                break;
            }
            case 2: {
                int luaChonKhachHang;
                do {
                	cout << endl;
                    cout << "\t\t\t-----------------------------------------------" << endl;
                    cout << "\t\t\t|               QUAN LY KHACH HANG            |" << endl;
                    cout << "\t\t\t-----------------------------------------------" << endl;
                    cout << "\t\t\t1. Them khach hang" << endl;
                    cout << "\t\t\t2. Sua khach hang" << endl;
                    cout << "\t\t\t3. Xoa khach hang" << endl;
                    cout << "\t\t\t4. Tim khach hang" << endl;
                    cout << "\t\t\t5. Quay lai" << endl;
                    cout << "Nhap lua chon cua ban: ";
                    cin >> luaChonKhachHang;
                    switch (luaChonKhachHang) {
                        case 1: quanLyKhachHang.themKhachHang(); break;
                        case 2: quanLyKhachHang.suaKhachHang(); break;
                        case 3: quanLyKhachHang.xoaKhachHang(); break;
                        case 4: quanLyKhachHang.timKhachHang(); break;
                        case 5: break;
                        default: cout << "Lua chon khong hop le!\n"; break;
                    }
                } while (luaChonKhachHang != 5);
                quanLyKhachHang.ghiFile();
                break;
            }
            case 3: {
            	menuquanlydonhang(qldonhang);
				break;
			}
			case 4: {
				menuquanlytheloaitacgia(qltheloaitacgia);
				break;
			}
			case 5: {
					duan.menu();
					break;
			}
			case 6: {
				int luachonnv;
				do {
					cout << endl;
					cout << "\t\t\t-----------------------------------------------" << endl;
                    cout << "\t\t\t|                QUAN LY NHAN VIEN            |" << endl;
                    cout << "\t\t\t-----------------------------------------------" << endl;
					cout << "\t\t\t1. Them Nhan Vien" << endl;
			        cout << "\t\t\t2. Xem Danh Sach Nhan Vien" << endl;
			        cout << "\t\t\t3. Sua Thong Tin Nhan Vien" << endl;
			        cout << "\t\t\t4. Xoa Nhan Vien" << endl;
			        cout << "\t\t\t5. Tim Kiem Nhan Vien" << endl;
			        cout << "\t\t\t6. Quay lai"<< endl;
			        cout << "Nhap lua chon cua ban: ";
			        cin >> luachonnv;
			        cin.ignore();
			        switch(luachonnv){
			        	case 1: qlNhanVien.themNhanVien(); break;
			        	case 2: qlNhanVien.hienThiDanhSach(); break;
			        	case 3: {
			        		string ten;
			                cout << "Nhap Ten Nhan Vien Can Sua: ";
			                getline(cin, ten);
			                qlNhanVien.suaThongTinNhanVien(ten);
							break;
						}
						case 4: {
							string ten;
			                cout << "Nhap Ten Nhan Vien Can Xoa: ";
			                getline(cin, ten);
			                qlNhanVien.xoaNhanVien(ten);
							break;
						}
						case 5: {
							string ten;
			                cout << "Nhap Ten Nhan Vien Can Tim: ";
			                getline(cin, ten);
			                qlNhanVien.timKiemNhanVien(ten);
							break;
						}
						case 6: qlNhanVien.ghiFile(); break;
						default: cout << "Lua chon khong hop le!\n"; break;
					}
				}while(luachonnv != 6);
				break;
			}
			case 7: {
				int luachonbaocao;
				do {
					cout << endl;
					cout << "\t\t\t-----------------------------------------------" << endl;
                    cout << "\t\t\t|            QUAN LY BAO CAO DOANH THU        |" << endl;
                    cout << "\t\t\t-----------------------------------------------" << endl;
					cout << "\t\t\t1. Tao Bao Cao Doanh Thu" << endl;
        			cout << "\t\t\t2. Xem Bao Cao Doanh Thu" << endl;	
        			cout << "\t\t\t3. Quay lai" << endl;
        			cout << "Nhap lua chon cua ban: ";
        			cin >> luachonbaocao;
        			switch(luachonbaocao){
        				case 1: qlBaoCao.taoBaoCao(); break;
        				case 2: qlBaoCao.hienThiBaoCao(); break;
        				case 3: qlBaoCao.ghiFile(); break;
        				default: cout << "Lua chon khong hop le!\n"; break;
					}
				}while(luachonbaocao != 3);
				break;
			}
            case 8: break;
            default: cout << "Lua chon khong hop le!\n"; break;
        }
    } while (luaChon != 8);
    return 0;
}
