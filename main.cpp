#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Khai báo cấu trúc sản phẩm
struct Product {
    string name;
    double price;
    int quantity;
};

// Danh sách sản phẩm
vector<Product> products;

// Hàm thêm sản phẩm mới
void addProduct() {
    Product product;
    cout << "Nhập tên sản phẩm: ";
    cin.ignore();
    getline(cin, product.name);
    cout << "Nhập giá sản phẩm: ";
    cin >> product.price;
    cout << "Nhập số lượng sản phẩm: ";
    cin >> product.quantity;
    products.push_back(product);
    cout << "Đã thêm sản phẩm thành công!\n";
}

// Hàm hiển thị danh sách sản phẩm
void displayProducts() {
    cout << "Danh sách sản phẩm:\n";
    for (size_t i = 0; i < products.size(); ++i) {
        cout << i + 1 << ". " << products[i].name 
             << " - Giá: " << products[i].price 
             << " - Số lượng: " << products[i].quantity << endl;
    }
}

// Hàm bán sản phẩm
void sellProduct() {
    displayProducts();
    int productIndex, quantity;
    cout << "Nhập số thứ tự sản phẩm muốn mua: ";
    cin >> productIndex;
    cout << "Nhập số lượng muốn mua: ";
    cin >> quantity;

    // Kiểm tra sản phẩm có đủ số lượng không
    if (productIndex > 0 && productIndex <= products.size() && products[productIndex - 1].quantity >= quantity) {
        products[productIndex - 1].quantity -= quantity;
        double total = quantity * products[productIndex - 1].price;
        cout << "Tổng tiền: " << total << endl;
        cout << "Đã bán thành công!\n";
    } else {
        cout << "Không đủ số lượng hoặc sản phẩm không tồn tại!\n";
    }
}

// Hàm hiển thị hóa đơn
void displayInvoice() {
    cout << "Hóa đơn bán hàng:\n";
    for (size_t i = 0; i < products.size(); ++i) {
        if (products[i].quantity < products.size()) {
            cout << products[i].name 
                 << " - Số lượng còn lại: " << products[i].quantity 
                 << " - Giá: " << products[i].price << endl;
        }
    }
}

int main() {
    int choice;
    do {
        cout << "\nChương trình Quản lý Bán Hàng\n";
        cout << "1. Thêm sản phẩm mới\n";
        cout << "2. Hiển thị danh sách sản phẩm\n";
        cout << "3. Bán sản phẩm\n";
        cout << "4. Hiển thị hóa đơn\n";
        cout << "5. Thoát\n";
        cout << "Nhập lựa chọn của bạn: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                sellProduct();
                break;
            case 4:
                displayInvoice();
                break;
            case 5:
                cout << "Cảm ơn bạn đã sử dụng chương trình!\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ! Vui lòng thử lại.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
