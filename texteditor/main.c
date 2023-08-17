#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>  // wait()関数を使用するために追加
#include <unistd.h>

int main() {
    // 新しいプロセスを生成
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // 子プロセスの処理
        printf("\033[8;40;100t");  // ターミナルのサイズを設定
        printf("\033[2J");         // 画面をクリア
        printf("\033[;H");        // カーソルを画面の先頭に移動
        printf("\n\n\n\n\n\n");   // 上にスペースを開けて中央に表示
        printf("\033[1;37m");     // テキストの色を白に設定
        printf("     Hello, World!\n");
        printf("\033[0m");        // テキストの色をリセット
        exit(EXIT_SUCCESS);
    } else {
        // 親プロセスの処理
        wait(NULL);  // 子プロセスの終了を待つ
    }

    return 0;
}
