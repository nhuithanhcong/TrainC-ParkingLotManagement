# TrainC-ParkingLotManagement
Mini Parking Management Project

Hệ thống quản lý bãi xe đơn giản viết bằng C, hỗ trợ quản lý đa luồng dữ liệu thông qua các module.

## Chức năng chính
- Nhập xe vào bãi (Ghi lại giờ tự động).
- Cho xe ra bãi & Tính tiền (Dựa trên thời gian đỗ và loại xe).
- Tìm kiếm xe theo biển số.
- Thống kê doanh thu trong ngày.
- Lưu trữ dữ liệu vào file `data/vehicles.dat`.

## Cấu trúc thư mục
- `main.c`: Menu chính và điều hướng.
- `parking.h/c`: Nghiệp vụ bãi xe.
- `billing.h/c`: Logic tính toán hóa đơn.
- `fileio.h/c`: Xử lý tệp tin.
- `utils.h/c`: Định nghĩa Struct và hàm tiện ích.

## Yêu cầu hệ thống
- Trình biên dịch C (GCC/MinGW).
- IDE khuyến nghị: Dev-C++ hoặc VS Code.
