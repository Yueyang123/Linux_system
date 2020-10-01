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
 * 
 */

/*
 * @Descripttion: 
 * @version: 
 * @Author: Yueyang
 * @email: 1700695611@qq.com
 * @Date: 2020-10-01 12:50:08
 * @LastEditors: Yueyang
 * @LastEditTime: 2020-10-01 13:16:18
 */

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc,void** argv)
{
    char *data,*filename;
    int fd,ret,count;
    if(argc!=4)
    {
        printf("please choose file");
        return -1;
    }
    count=atoi(argv[3]);
    data=argv[2];
    filename=argv[1];

    fd =open(filename,O_WRONLY|O_APPEND);
    printf("fd_id:%d\n",fd);
    if(fd<0)
    {
        perror("open error\n");
        return -1;
    }
    ret =write(fd,data,count);
    if(ret==-1)
    {
        perror("write error\n");
        return -1;
    }
    
    return 0;
}