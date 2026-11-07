#include "base.h"

//敵の移動方向を決める
void moveEnemy(void){
    for(int i = 0; i < teki; i++){  //1体ずつ
        enemy[i].dire = rand() % 10;    //方向を決める
        if(mapJudge(enemy[i].xposi, enemy[i].yposi - upper, enemy[i].dire, "B") == 0 && mapJudge(enemy[i].xposi, enemy[i].yposi - upper, enemy[i].dire, "S") == 0 && mapJudge(enemy[i].xposi, enemy[i].yposi - upper, enemy[i].dire, "T") == 0&& mapJudge(enemy[i].xposi, enemy[i].yposi - upper, enemy[i].dire, "R") == 0 && mapJudge(enemy[i].xposi, enemy[i].yposi - upper, enemy[i].dire, "G") == 0 && mapJudge(enemy[i].xposi, enemy[i].yposi - upper, enemy[i].dire, "A") == 0){      //入っては行けない場所に入っていないかどうか
            if(enemy[i].dire == 0 || enemy[i].dire == 1) enemy[i].yposi -= images / 4;      //上方向
            if(enemy[i].dire == 2 || enemy[i].dire == 3) enemy[i].xposi += images / 4;      //右方向
            if(enemy[i].dire == 4 || enemy[i].dire == 5) enemy[i].yposi += images / 4;      //下方向
            if(enemy[i].dire == 6 || enemy[i].dire == 7) enemy[i].xposi -= images / 4;      //左方向
        }
    }
}

//アイテムを取得したか判定する
void itemJudge(struct CHARACTER *c){
    for(int i = 0; i < xnum; i++){
        for(int j = 0; j < ynum; j++){
            if(strncmp("S", &map[j][i], 1) == 0){   //アイテムのマス
                if((abs(c->xposi + W - (32 * i)) < 20 && abs(c->yposi + H - upper - (32 * j)) < 20) || (c->xposi + W == (32 * i) && c->yposi + H  - upper == (32 * j))){    //一致しているか一部分かぶっているか
                    map[j][i] = 'O';    //マップ上から消す
                    c->strength += 5;   //強さを増やす
                    score += 10;    //スコアを増やす
                }
            }
        }
    }
}

//画面が動く範囲を決める
int moverange(int num){
    int x = 0, y = 0;
    if(H == 0 && W == 0){
        if(chara.xposi >= images*5 && chara.yposi >= images*5 + upper){
            y = images / 4;
            x = images / 4;
        }else if(chara.xposi >= images*5 && chara.yposi < images*5 + upper){
            y = 0;
            x = images / 4;
        }else if(chara.xposi < images*5 && chara.yposi >= images*5 + upper){
            y = images / 4;
            x = 0;
        }else if(chara.xposi < images*5 && chara.yposi < images*5 + upper){
            y = 0;
            x = 0;
        }
    }else if(H == 0 && W == (xnum - 11) * images){
        if(chara.xposi > images*5 && chara.yposi >= images*5 + upper){
            y = images / 4;
            x = 0;
        }else if(chara.xposi > images*5 && chara.yposi < images*5 + upper){
            y = 0;
            x = 0;
        }else if(chara.xposi <= images*5 && chara.yposi >= images*5 + upper){
            y = images / 4;
            x = images / 4;
        }else if(chara.xposi <= images*5 && chara.yposi < images*5 + upper){
            y = 0;
            x = images / 4;
        }
    }else if(H == (ynum - 11) * images && W == 0){
        if(chara.xposi >= images*5 && chara.yposi > images*5 + upper){
            y = 0;
            x = images / 4;
        }else if(chara.xposi >= images*5 && chara.yposi <= images*5 + upper){
            y = images / 4;
            x = images / 4;
        }else if(chara.xposi < images*5 && chara.yposi > images*5 + upper){
            y = 0;
            x = 0;
        }else if(chara.xposi < images*5 && chara.yposi <= images*5 + upper){
            y = images / 4;
            x = 0;
        }
    }else if(H == (ynum - 11) * images && W == (xnum - 11) * images){
        if(chara.xposi > images*5 && chara.yposi > images*5 + upper){
            y = 0;
            x = 0;
        }else if(chara.xposi > images*5 && chara.yposi <= images*5 + upper){
            y = images / 4;
            x = 0;
        }else if(chara.xposi <= images*5 && chara.yposi > images*5 + upper){
            y = 0;
            x = images / 4;
        }else if(chara.xposi <= images*5 && chara.yposi <= images*5 + upper){
            y = images / 4;
            x = images / 4;
        }
    }else if(H == 0){
        if(chara.yposi < images*5 + upper){
            y = 0;
            x = images / 4;
        }else if(chara.yposi >= images*5 + upper){
            y = images / 4;
            x = images / 4;
        }
    }else if(H == (ynum - 11) * images){
        if(chara.yposi <= images*5 + upper){
            y = images / 4;
            x = images / 4;
        }else if(chara.yposi > images*5 + upper){
            y = 0;
            x = images / 4;
        }
    }else if(W == 0){
        if(chara.xposi < images*5){
            y = images / 4;
            x = 0;
        }else if(chara.xposi >= images*5){
            y = images / 4;
            x = images / 4;
        }
    }else if(W == (xnum - 11) * images){
        if(chara.xposi <= images*5){
            y = images / 4;
            x = images / 4;
        }else if(chara.xposi > images*5){
            y = images / 4;
            x = 0;
        }
    }else{
        y = images / 4;
        x = images / 4;
    }

    if(num == 0) return x;
    else return y;
}

//壁に当たったかどうか判定する
int mapJudge(int a, int b, int dire, char *str){
    int cx = a / images;
    int cy = b / images;
    int value = 0;
    
    switch(dire){
        case 0:             //上
            if(a % images == 0 && b % images == 0){
                if(strncmp(str, &map[cy - 1][cx], 1) == 0) value = 1;
            }
            else if(a % images == 0 && b % images != 0) value = 0;
            else{
                cy = (b - 1) / images;
                if(strncmp(str, &map[cy][cx], 1) == 0 || strncmp(str, &map[cy][cx + 1], 1) == 0) value = 1;
            }
            break;
        case 2:             //右
            if(a % images == 0 && b % images == 0){
                if(strncmp(str, &map[cy][cx + 1], 1) == 0) value = 1;
            }
            else if(a % images != 0 && b % images == 0) value = 0;
            else{
                if(strncmp(str, &map[cy][cx + 1], 1) == 0 || strncmp(str, &map[cy + 1][cx + 1], 1) == 0) value = 1;
            }
            break;
        case 4:             //下
            if(a % images == 0 && b % images == 0){
                if(strncmp(str, &map[cy + 1][cx], 1) == 0) value = 1;
            }
            else if(a % images == 0 && b % images != 0) value = 0;
            else{
                if(strncmp(str, &map[cy + 1][cx], 1) == 0 ||  strncmp(str, &map[cy + 1][cx + 1], 1) == 0) value = 1;
            }
            break;
        case 6:             //左
            if(a % images == 0 && b % images == 0){
                if(strncmp(str, &map[cy][cx - 1], 1) == 0) value = 1;
            }
            else if(a % images != 0 && b % images == 0) value = 0;
            else{
                cx = (a - 1) / images;
                if(strncmp(str, &map[cy][cx], 1) == 0 || strncmp(str, &map[cy + 1][cx], 1) == 0) value = 1;
            }
            break;
        default:
            value = 1;
            break;
    }
    return value;
}

//敵と当たったか判定する
void enemyJudge(struct CHARACTER *c){
    for(int i = 0;i < teki; i++){   //1体ずつ
        if(enemy[i].lord == 1){     //生きているかどうか
            if((abs(c->xposi + W - enemy[i].xposi) < 20 && abs(c->yposi + H - enemy[i].yposi) < 20) || (c->xposi + W == enemy[i].xposi && c->yposi + H == enemy[i].yposi)){     //一致しているか一部分かぶっているか
                if(c->strength > enemy[i].strength){    //敵の方が弱いとき
                    count += 30;    //30秒増やす
                    enemy[i].lord = 0;  //命がつきる
                    score += 5; //5増やす
                } else if(timelag == 0){    //敵の方が強いとき
                    count -= 20;    //20秒減らす
                    timelag = 1;    //タイムラグ発生
                }
            }
        }
    }
}

//クリアチェックをする
void clearcheck(void){
    if(MODE == move || MODE == pause){
        if((chara.xposi + W) >= (xnum - 2) * images && (chara.yposi + H) >=  (ynum - 3) * images){  //ゴール地点内
            cleartime = count;  //クリアタイムを格納
            MODE = clear;   //モードを切り替える
            score += cleartime;     //スコアにクリアタイムを足す
        }
    }
}
