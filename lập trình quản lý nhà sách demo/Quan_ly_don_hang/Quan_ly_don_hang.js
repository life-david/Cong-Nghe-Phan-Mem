// Lấy danh sách đơn hàng từ localStorage hoặc khởi tạo mảng rỗng nếu không có dữ liệu
let orders = JSON.parse(localStorage.getItem("orders")) || [];

// Các biến toàn cục dùng để lưu tạm thông tin đơn hàng và sách được chọn
let orderHeader = null;       // Lưu thông tin chung của đơn hàng (mã, ngày, khách hàng)
let selectedBookOrder = null; // Lưu thông tin sách được chọn (tên sách, số lượng mua, tổng giá)

// Hàm tạo đơn hàng mới
function taoDonHang() {
  // Nhập thông tin đơn hàng qua prompt
  let idInput = prompt("Nhập mã đơn hàng (tối đa 5 chữ số):");
  if (!idInput) {
    alert("Mã đơn hàng không được để trống!");
    return;
  }
  // Chuyển mã đơn hàng thành số và đảm bảo nó tối đa 5 chữ số
  let idNumber = parseInt(idInput, 10);
  if (isNaN(idNumber)) {
    alert("Mã đơn hàng phải là số!");
    return;
  }
  if (idNumber >= 100000) {
    alert("Mã đơn hàng chỉ tối đa 5 chữ số!");
    return;
  }
  // Định dạng mã đơn hàng thành chuỗi 5 ký tự (thêm số 0 ở đầu nếu cần)
  let formattedId = idNumber.toString().padStart(5, "0");

  let date = prompt("Nhập ngày đơn hàng (DD-MM-YYYY):");
  let customer = prompt("Nhập tên khách hàng:");
  
  // Nếu đủ thông tin, lưu thông tin đơn hàng chung vào biến orderHeader
  if (formattedId && date && customer) {
    orderHeader = { id: formattedId, date: formatDateToISO(date), customer };
    // Sau đó, mở panel để chọn sách từ Quản Lý Sách
    openBookPanel();
  } else {
    alert("Thông tin đơn hàng không đầy đủ!");
  }
}

// Hàm hiển thị panel chọn sách
function openBookPanel() {
  let panel = document.getElementById("book-panel");
  panel.classList.add("show"); // Thêm lớp "show" để hiển thị panel

  // Lấy danh sách sách từ localStorage (Quản Lý Sách)
  let books = JSON.parse(localStorage.getItem("books")) || [];
  let bookSelectList = document.getElementById("book-select-list");

  // Hiển thị danh sách sách trong bảng panel
  bookSelectList.innerHTML = books.map((book, index) => {
    return `<tr>
      <td>${book.name}</td>
      <td>${parseFloat(book.price).toLocaleString()} VNĐ</td>
      <td>${book.quantity}</td>
      <td><button onclick="selectBook(${index})">Chọn</button></td>
    </tr>`;
  }).join("");
}

// Hàm ẩn panel chọn sách
function closeBookPanel() {
  let panel = document.getElementById("book-panel");
  panel.classList.remove("show");
}

// Hàm xử lý khi người dùng chọn sách từ panel
function selectBook(index) {
  let books = JSON.parse(localStorage.getItem("books")) || [];
  let book = books[index];

  // Nhập số lượng mua của sách được chọn
  let qtyInput = prompt("Nhập số lượng sách mua (Có sẵn: " + book.quantity + "):");
  let qty = parseInt(qtyInput);
  
  // Kiểm tra số lượng nhập vào
  if (isNaN(qty) || qty <= 0) {
    alert("Số lượng không hợp lệ!");
    return;
  }
  if (qty > book.quantity) {
    alert("Không đủ số lượng sách! Số lượng hiện có: " + book.quantity);
    return;
  }
  
  // Tính tổng giá trị đơn hàng dựa trên đơn giá của sách và số lượng mua
  let price = parseFloat(book.price);
  let totalValue = price * qty;
  
  // Lưu thông tin sách được chọn vào biến selectedBookOrder
  selectedBookOrder = { bookName: book.name, quantity: qty, totalValue: totalValue };
  
  closeBookPanel(); // Đóng panel chọn sách
  completeOrderCreation(); // Hoàn tất quá trình tạo đơn hàng
}

// Hàm hoàn tất quá trình tạo đơn hàng
function completeOrderCreation() {
  if (!orderHeader || !selectedBookOrder) {
    alert("Thông tin đơn hàng không đầy đủ!");
    return;
  }
  // Gộp thông tin đơn hàng chung và thông tin sách được chọn thành đối tượng đơn hàng
  let order = {
    id: orderHeader.id,
    date: orderHeader.date,
    customer: orderHeader.customer,
    bookName: selectedBookOrder.bookName,
    quantity: selectedBookOrder.quantity,
    totalValue: selectedBookOrder.totalValue
  };
  
  // Thêm đơn hàng vào danh sách và lưu vào localStorage
  orders.push(order);
  localStorage.setItem("orders", JSON.stringify(orders));
  
  // Cập nhật doanh thu theo ngày: nếu chưa có, khởi tạo bằng 0, sau đó cộng thêm tổng giá của đơn hàng
  updateRevenue(order.date, order.totalValue);
  
  // Cập nhật số lượng sách trong Quản Lý Sách (giảm số lượng theo sách được mua)
  updateBookQuantity(order.bookName, order.quantity);
  
  alert("Đơn hàng đã được tạo, doanh thu cập nhật và số lượng sách giảm.");
  
  // Cập nhật bảng đơn hàng hiển thị
  updateOrderTable();
  
  // Nếu có đơn hàng, hiển thị liên kết chuyển sang trang Báo Cáo Doanh Thu
  if (orders.length > 0) {
    document.getElementById("hidden-revenue-link").style.display = "inline-block";
  }
  
  // Cuộn trang xuống để hiển thị bảng đơn hàng
  document.getElementById("order-table").scrollIntoView({ behavior: "smooth" });
  
  // Reset thông tin tạm
  orderHeader = null;
  selectedBookOrder = null;
}

// Hàm cập nhật doanh thu theo ngày
function updateRevenue(date, amount) {
  let revenue = JSON.parse(localStorage.getItem("revenue")) || {};
  if (!revenue[date]) {
    revenue[date] = 0;
  }
  revenue[date] += amount;
  localStorage.setItem("revenue", JSON.stringify(revenue));
}

// Hàm cập nhật số lượng sách trong Quản Lý Sách
function updateBookQuantity(bookName, quantityPurchased) {
  let books = JSON.parse(localStorage.getItem("books")) || [];
  let found = false;
  books = books.map(book => {
    if (book.name.toLowerCase() === bookName.toLowerCase()) {
      found = true;
      // Giảm số lượng sách, đảm bảo không âm
      book.quantity = Math.max(book.quantity - quantityPurchased, 0);
      // Cập nhật lại Tổng Giá của sách dựa trên số lượng mới và đơn giá
      book.totalPrice = book.quantity * parseFloat(book.price);
    }
    return book;
  });
  if (!found) {
    alert("Không tìm thấy sách: " + bookName + " trong Quản Lý Sách.");
  }
  localStorage.setItem("books", JSON.stringify(books));
}

// Hàm xóa đơn hàng theo chỉ số index
function xoaDonHangTheoMa(index) {
  let order = orders[index];
  if (confirm("Bạn có chắc muốn xóa đơn hàng " + order.id + "?")) {
    let revenue = JSON.parse(localStorage.getItem("revenue")) || {};
    if (revenue[order.date]) {
      revenue[order.date] -= order.totalValue;
      if (revenue[order.date] < 0) revenue[order.date] = 0;
      localStorage.setItem("revenue", JSON.stringify(revenue));
    }
    // Khi xóa đơn hàng, số lượng sách không phục hồi
    orders.splice(index, 1);
    localStorage.setItem("orders", JSON.stringify(orders));
    updateOrderTable();
    if (orders.length === 0) {
      document.getElementById("hidden-revenue-link").style.display = "none";
    }
    alert("Đã xóa đơn hàng " + order.id);
  }
}

// Hàm xóa hết các đơn hàng
function xoaHetMa() {
  if (confirm("Bạn có chắc muốn xóa hết các đơn hàng?")) {
    orders = [];
    localStorage.setItem("orders", JSON.stringify(orders));
    localStorage.setItem("revenue", JSON.stringify({}));
    updateOrderTable();
    document.getElementById("hidden-revenue-link").style.display = "none";
    alert("Đã xóa hết các đơn hàng.");
  }
}

// Hàm cập nhật bảng hiển thị danh sách đơn hàng
function updateOrderTable() {
  let orderList = document.getElementById("order-list");
  orderList.innerHTML = orders.map((order, index) => {
    let displayDate = formatDateToDisplay(order.date);
    return `<tr>
      <td>${order.id}</td>
      <td>${displayDate}</td>
      <td>${order.customer}</td>
      <td>${order.bookName}</td>
      <td>${order.quantity}</td>
      <td>${order.totalValue.toLocaleString()} VNĐ</td>
      <td><button class="delete-btn" onclick="xoaDonHangTheoMa(${index})">Xóa</button></td>
    </tr>`;
  }).join("");
}

// Hàm chuyển hướng về trang chủ
function quayLai() {
  location.href = "../trang_chu.html"; // Điều chỉnh đường dẫn nếu cần
}

// Hàm chuyển đổi ngày từ định dạng DD-MM-YYYY sang YYYY-MM-DD
function formatDateToISO(date) {
  let [day, month, year] = date.split("-");
  return `${year}-${month}-${day}`;
}

// Hàm chuyển đổi ngày từ YYYY-MM-DD sang DD-MM-YYYY để hiển thị
function formatDateToDisplay(date) {
  let [year, month, day] = date.split("-");
  return `${day}-${month}-${year}`;
}

// Khi trang được tải, cập nhật bảng đơn hàng và hiển thị liên kết doanh thu nếu có đơn hàng
window.onload = function() {
  orders = JSON.parse(localStorage.getItem("orders")) || [];
  updateOrderTable();
  if (orders.length > 0) {
    document.getElementById("hidden-revenue-link").style.display = "inline-block";
  } else {
    document.getElementById("hidden-revenue-link").style.display = "none";
  }
};
