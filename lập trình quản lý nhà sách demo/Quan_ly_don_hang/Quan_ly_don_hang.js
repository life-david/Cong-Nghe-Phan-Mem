let orders = JSON.parse(localStorage.getItem("orders")) || [];

function taoDonHang() {
    let id = prompt("Nhập mã đơn hàng:");
    let date = prompt("Nhập ngày đơn hàng (YYYY-MM-DD):");
    let customer = prompt("Nhập tên khách hàng:");
    let details = prompt("Nhập chi tiết đơn hàng:");

    if (id && date && customer && details) {
        orders.push({ id, date, customer, details });
        localStorage.setItem("orders", JSON.stringify(orders));
        hienThiDonHang();
    }
}

function xoaDonHangTheoMa() {
    let id = prompt("Nhập mã đơn hàng cần xóa:");
    let index = orders.findIndex(order => order.id === id);
    if (index !== -1) {
        orders.splice(index, 1);
        localStorage.setItem("orders", JSON.stringify(orders));
        hienThiDonHang();
    }
}

function xoaHetMa() {
    if (confirm("Bạn có chắc chắn muốn xóa hết mã đơn hàng không?")) {
        orders = [];
        localStorage.setItem("orders", JSON.stringify(orders));
        hienThiDonHang();
    }
}

function xemLichSu() {
    hienThiDonHang();
}

function lietKeDonCungNgay() {
    let date = prompt("Nhập ngày cần liệt kê (YYYY-MM-DD):");
    let filteredOrders = orders.filter(order => order.date === date);
    hienThiDonHang(filteredOrders);
}

function lietKeDonCungKhachHang() {
    let customer = prompt("Nhập tên khách hàng cần liệt kê:");
    let filteredOrders = orders.filter(order => order.customer === customer);
    hienThiDonHang(filteredOrders);
}

function hienThiDonHang(filteredList = orders) {
    let list = document.getElementById("order-list");
    list.innerHTML = filteredList.map(order => {
        return `
            <tr>
                <td>${order.id}</td>
                <td>${order.date}</td>
                <td>${order.customer}</td>
                <td>${order.details}</td>
                <td><button class="delete-btn" onclick="xoaDonHangTheoMa('${order.id}')">Xóa</button></td>
            </tr>
        `;
    }).join("");
}

function quayLai() {
    location.href = "../trang_chu.html"; // Adjust the path as necessary
}

// Hiển thị danh sách đơn hàng khi tải trang
hienThiDonHang();