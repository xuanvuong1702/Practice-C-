#include "forking.h"
#include <unistd.h> 

void SimpleFork()
{
    printf("Tôi được in một lần!\n");
    
    fork();
    // Bây giờ có hai tiến trình đang chạy
    // và mỗi tiến trình sẽ in ra dòng tiếp theo.
    printf("Bạn thấy dòng này hai lần!\n");
}