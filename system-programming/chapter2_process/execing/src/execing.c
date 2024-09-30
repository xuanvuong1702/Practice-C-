#include "execing.h"
#include <unistd.h>
#include <fcntl.h> // O_CREAT, O_APPEND etc. được định nghĩa ở đây


void simple_exec()
{
    close(1); // đóng đầu ra tiêu chuẩn
    open("log.txt", O_RDWR | O_CREAT | O_APPEND);
    puts("Nhật ký của thuyền trưởng");

    // Đổi thư mục làm việc
    chdir("C:\\Users\\63200320\\Documents\\source\\github\\Practice-Cpp\\system-programming");
    // execl( tệp thực thi,  đối số cho tệp thực thi bao gồm tên chương trình và NULL ở cuối)

    execl("/bin/ls", /* Các mục còn lại được gửi đến ls*/ "/bin/ls", ".", (char *)NULL); // "ls ."
    perror("exec thất bại");
    return 0; // Không mong đợi
}