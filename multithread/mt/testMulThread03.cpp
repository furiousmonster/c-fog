/*题目：子线程循环 10 次，接着主线程循环 100 次，接着又回到子线程循环 10 次，接着再回到主线程又循环 100 次。          
如此循环50次，试写出代码。子线程与主线程必有一个满足条件(flag == num),
不满足条件的那个线程不可能获取unique_lock(会在wait中释放)，只有满足条件的线程才能获取锁，执行程序
*/

#include<thread>
#include<iostream>
#include<mutex>
#include<condition_variable>

using namespace std;

mutex m;//保护条件的互斥访问
condition_variable cond;//条件变量
int flag = 10;//全局变量的值对线程来说是共享的 

void fun(int num) 
{
    for (int i = 0; i<50; i++) 
    {
        cout<<"num111111111111 = "<<num<<endl;
        unique_lock<mutex> lk(m);//A unique lock is an object that manages a mutex object with unique ownership in both states: locked and unlocked.  
        cout<<"num222222222222 = "<<num<<endl;
        //while(1)
        while (flag != num)//线程1 显然开始不进入 while  wait函数前面切记使用while 防止惊群现象
            cond.wait(lk);//在调用wait时会执行 lk.unlock()  哪个线程调用wait 哪个线程就释放mutex  因为这里的锁也是需要竞争的
        for (int j = 0; j<num; j++)
            cout << j << " ";
        cout << endl;
        flag = (num == 10) ? 100 : 10;
        cond.notify_one();//被阻塞的线程唤醒后lk.lock()恢复在调用wait前的状态  
    }
}

int main() {
    thread child(fun, 10);
    fun(100);
    child.join();
    while(1);
    return 0;
}