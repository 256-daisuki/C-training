#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define STACK_SIZE 64 // doubleの大きさ

typedef struct {
    double data[STACK_SIZE];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1; // 初期化 元が-1らしい(ChatGPT情報)
}

bool push(Stack* stack, double value) { // topにまだスタックを積めるか確認
    return stack->top < STACK_SIZE - 1 ? (stack->data[++stack->top] = value, true) : false;
}

bool pop(Stack* stack, double* value) { // topがnot 空だったらデータを取り出してポインタに格納するやつ
    return stack->top >= 0 ? (*value = stack->data[stack->top--], true) : false;
}

int main() {
    printf("hでヘルプを表示 qで終了\n");
    Stack stack;
    initStack(&stack);
    
    char input[100];
    double result;
    int help_num = 0;
    while (true) {
        fgets(input, sizeof(input), stdin);
        
        if (input[0] == 'q') // qが押されたら終わらせる
            break;
        
        if (input[0] == 'h') { // hが押されたらヘルプを表示
            printf("逆ポーランド記法は、1+1 を 1 1 + と入力する書き方だよ　()を使わないから早く打てたりするらしい　電卓はHPぐらいしか作ってなかったけどね　詳しくは自分で調べて\n操作方法 + - * / のよくあるやつで四則演算 ^でx乗 rでルートを使えるよ\n");
            help_num++;
        }

        char* token = strtok(input, " "); // " "で区切るやつ
        
        while (token != NULL) { //この中でbreakな感じのことが起きると、入力モードに戻される
            if (isdigit(*token)) {
                push(&stack, atof(token));
            } else if (strchr("+-*/^r", *token) != NULL) { // 文字一覧（？）
                double a, b;
                pop(&stack, &b);
                if (*token == 'r') { // ルートの処理
                    if (b >= 0) {
                        push(&stack, sqrt(b));
                    } else {
                        printf("エラー：虚数に対応してません\n");
                        help_num++;
                    }
                } else {
                    pop(&stack, &a);
                    switch (*token) {
                        case '+': push(&stack, a + b); break;
                        case '-': push(&stack, a - b); break;
                        case '*': push(&stack, a * b); break;
                        case '/':
                            if (b == 0) {
                                printf("エラー：ゼロ除算しようとしないで\n");
                                help_num++;
                                break;
                            }
                            push(&stack, a / b);
                            break;
                        case '^': // ('^')// シマエナガ
                            push(&stack, pow(a, b));
                            break;
                        }
                    }
                }
            token = strtok(NULL, " ");
        }
        pop(&stack, &result);
        if (help_num == 1) { // help_numが1なら計算結果を表示しないでhelp_numを0にする　それ以外なら普通に結果を表示
            help_num = 0;
        } else {
            printf("結果: %f\n", result);
        }
    }
    return 0;
}