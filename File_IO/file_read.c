/*
 *                        _oo0oo_
 *                       o8888888o
 *                       88" . "88
 *                       (| -_- |)
 *                       0\  =  /0
 *                     ___/`---'\___
 *                   .' \\|     |// '.
 *                  / \\|||  :  |||// \
 *                 / _||||| -:- |||||- \
 *                |   | \\\  - /// |   |
 *                | \_|  ''\---/''  |_/ |
 *                \  .-\__  '-'  ___/-. /
 *              ___'. .'  /--.--\  `. .'___
 *           ."" '<  `.___\_<|>_/___.' >' "".
 *          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *          \  \ `_.   \_ __\ /__ _/   .-` /  /
 *      =====`-.____`.___ \_____/___.-`___.-'=====
 *                        `=---='
 * 
 * 
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *            佛祖保佑       永不宕机     永无BUG
 */

/*
 * @Descripttion: 
 * @version: 
 * @Author: Yueyang
 * @email: 1700695611@qq.com
 * @Date: 2020-10-01 12:26:49
 * @LastEditors: Yueyang
 * @LastEditTime: 2020-10-01 12:53:24
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc ,char** argv)
{
    //ssize_t long int
    //size_t  long unsigned int
    struct  stat buf;
    int len=0,ret=0;
    char* tbuf=malloc(3000*sizeof(char));
    char* start =tbuf;
    memset(tbuf,0,3000);
    if(argc !=2){
        printf("please input filename");
        return -1;
    }
    stat(argv[1],&buf);
    printf("data of this file :size %d \n",(int)buf.st_size);
    len =buf.st_size;

    int fd =open(argv[1],O_RDONLY|O_CREAT);
    if(fd==-1){
    perror("open file error");   
    return -1;
    }

    while (len!=0&&(ret=read(fd,tbuf,len))!=0)
    {
        if(ret==-1){
            if(ret==EINTR)
                continue;
        perror("read");
        break;
        }
        len-=ret;
        tbuf+=ret;
    }
    for(ret=0;ret<buf.st_size;ret+=sizeof(char))
    printf("%c",start[ret]);

    free(start);
    return 0;
}