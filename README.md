# SM3-Birthday_attack
利用生日攻击找n比特碰撞的原像
​ 对于任意消息（这里只考虑数字字符串，其他字符串也可以转化到数字字符串）M，我们计算H=SM3(M)，如果我们只考虑前n比特（下文中的相等都是指前n比特），那么在前0-2^n范围内，至少存在一组碰撞的概率几乎是100%。

​ 那么对于特定的消息M，如何利用生日攻击去找到这个碰撞像呢？

​ 我们可以任取两个消息m1，m2，计算h=SM3(abs(M1-M2)，直到得到H= h


# 误差分析

假设存在M‘，有SM3(M)=SM3(M')，那么我们在前2^n比特范围内找到M'的概率是1/2^n,但是我们找两个数m1和m2，满足m1-m2 = M’的概率则是（C2n，2）/2^n,这个比较类似素数检测中的Poll_rho算法。
利用生日攻击找到任意一组前n比特的碰撞
​ 如果我们不是利用生日攻击去找碰撞像，而是单纯找两个消息m1和m2满足SM3(m1)=SM3(m2)，那么最简单的肯定还是穷举，使用hash表，遇到碰撞就输出。



# 代码说明

# int cmphash(unsigned char* H1,unsigned char* H2,int Len)    
因为我们只比较前几个bit，因为大端序的问题，这些比特是倒着存放的，进行处理


![image](https://user-images.githubusercontent.com/75195549/181441347-b88cf68a-bd98-444e-b13b-f8eb4c1995ca.png)



# int Pollard_Rho(uint image,unsigned char* H,uint c,uint* preiamge) 
经典的pollard rho算法，使用平方加c的方式进行套圈


![image](https://user-images.githubusercontent.com/75195549/181441549-a1ef1c17-0d7d-438d-a35e-127c42f9c7bc.png)



# void  PreimageAttack(uint image)
进行碰撞攻击


![image](https://user-images.githubusercontent.com/75195549/181441654-3261944d-6567-4626-a53a-db2d976b600d.png)



使用SM3(string input_str)直接打印出Hash值，也可以用SM3(string input_str,unsigned char* ouput)来获取hash值。



![image](https://user-images.githubusercontent.com/75195549/180794501-77883cf6-6676-474d-bfc0-0f5461d234a0.png)




main函数通过产生随机数字，作为字符串string计算hash值，然后通过Pollard_Rho方法，找到碰撞原像，碰撞的bit长度通过全局变量定义。




![image](https://user-images.githubusercontent.com/75195549/180794437-33e5c7b8-d297-4a5f-bcdc-13f8ca911387.png)







# 结果分析


16bit的原像碰撞很快




![image](https://user-images.githubusercontent.com/75195549/180797311-4016feb0-4de4-441b-8c4d-09de5e402368.png)




​ 24bit明显变慢




![image](https://user-images.githubusercontent.com/75195549/180797870-1f554189-441f-4b1c-b3cc-0455bb7abe6f.png)


这符合我们的预期

