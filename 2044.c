#include <stdio.h>
#include <string.h>

struct music {
    char name[40];
    int time;
    int score;
};

int main() {
    int listNum;  //歌曲清单总数
    int recordNum;  //记录总数
    struct music MusicList[1000];
    while (~scanf("%d", &listNum) && listNum) {
        int minutes;
        int seconds;
        //接收歌曲记录
        for (int i = 0; i < listNum; i++) {
            scanf("%s %d:%d", MusicList[i].name, &minutes, &seconds);
            MusicList[i].time = seconds + minutes * 60;
            MusicList[i].score = 0;
        }
        //接收听歌记录并计分
        char name[31];
        scanf("%d", &recordNum);
        for (int i = 0; i < recordNum; i++) {
            scanf("%s %d:%d", name, &minutes, &seconds);
            for (int j = 0; j < listNum; j++) {
                if (strcmp(name, MusicList[j].name) == 0) {
                    double totalTime = MusicList[j].time;
                    double listenTime = seconds + minutes * 60;
                    if (listenTime < totalTime / 5) {
                        MusicList[j].score += 0;
                    }
                    else if (listenTime < totalTime * 2 / 5) {
                        MusicList[j].score += 1;
                    }
                    else if (listenTime < totalTime * 3 / 5) {
                        MusicList[j].score += 2;
                    }
                    else if (listenTime < totalTime * 4 / 5) {
                        MusicList[j].score += 3;
                    }
                    else if (listenTime < totalTime) {
                        MusicList[j].score += 4;
                    }
                    else {
                        MusicList[j].score += 5;
                    }
                    break;
                }
            }
        }
        //排序输出
        struct music temp;
        for (int i = 0; i < listNum; i++) {
            for (int j = listNum - 2; j >= i; j--) {
                if (
                    MusicList[j].score < MusicList[j + 1].score ||
                    (MusicList[j].score == MusicList[j + 1].score && 
                    strcmp(MusicList[j].name, MusicList[j + 1].name) > 0)
                ) {
                    temp = MusicList[j];
                    MusicList[j] = MusicList[j + 1];
                    MusicList[j + 1] = temp;
                }
            }
            printf("%s %d\n", MusicList[i].name, MusicList[i].score);
        }
    }
}