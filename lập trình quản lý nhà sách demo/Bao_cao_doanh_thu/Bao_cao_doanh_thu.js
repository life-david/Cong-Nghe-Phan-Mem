let reports = JSON.parse(localStorage.getItem("reports")) || [];

function taoBaoCao() {
    let date = prompt("Nhập ngày báo cáo (YYYY-MM-DD):");
    let revenue = prompt("Nhập doanh thu:");
    let details = prompt("Nhập chi tiết báo cáo:");

    if (date && revenue && details) {
        reports.push({ date, revenue, details });
        localStorage.setItem("reports", JSON.stringify(reports));
        hienThiBaoCao();
    }
}

function xoaBaoCao(date) {
    let index = reports.findIndex(report => report.date === date);
    if (index !== -1) {
        reports.splice(index, 1);
        localStorage.setItem("reports", JSON.stringify(reports));
        hienThiBaoCao();
    }
}

function timBaoCao() {
    let keyword = document.getElementById("search").value.toLowerCase();
    let type = document.getElementById("search-type").value;

    let filteredReports = reports.map(report => {
        let value = report[type].toLowerCase();
        return {
            ...report,
            highlight: value.includes(keyword) && keyword !== "" ? keyword : null
        };
    });

    hienThiBaoCao(filteredReports);
}

function hienThiBaoCao(filteredList = reports) {
    let list = document.getElementById("report-list");
    list.innerHTML = filteredList.map(report => {
        let highlightedDate = highlightText(report.date, report.highlight);
        let highlightedRevenue = highlightText(report.revenue, report.highlight);
        let highlightedDetails = highlightText(report.details, report.highlight);

        return `
            <tr>
                <td>${highlightedDate}</td>
                <td>${highlightedRevenue}</td>
                <td>${highlightedDetails}</td>
                <td><button class="delete-btn" onclick="xoaBaoCao('${report.date}')">Xóa</button></td>
            </tr>
        `;
    }).join("");
}

function highlightText(text, keyword) {
    if (!keyword || !text.toLowerCase().includes(keyword)) return text;
    let regex = new RegExp(`(${keyword})`, "gi");
    return text.replace(regex, `<span class="highlight">$1</span>`);
}

function quayLai() {
    location.href = "../trang_chu.html"; // Adjust the path as necessary
}

// Hiển thị danh sách báo cáo khi tải trang
hienThiBaoCao();