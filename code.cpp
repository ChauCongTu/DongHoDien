#include <reg51.h>	//Khai báo thư viện
#define msec 1		//Định nghĩa biến msec kiểu dữ liệu là số nguyên, giá trị là 1
unsigned int arr[10]={0x40,0xF9,0x24,0x30,0x19,0x12,0x02,0xF8,0x00,0x10};	//Khai báo mảng arr có 10 phần tử
//khai báo các biến d, d0, d1, d2, d3, d4
sbit d4=P1^0;
sbit d3=P1^1;
sbit d2=P1^2;
sbit d1=P1^3;
sbit d0=P1^4;
sbit d= P1^5;
unsigned int v1,v2,v3,v4,v0,v5,v6;	//Khai báo biến toàn cục v0 -> v6
void delay(unsigned int count)	//Code hàm delay truyền vào 1 giá trị count
{
	unsigned int j,k;	//Khai báo 2 biến j, k kiểu số nguyên
	for (j=0;j<=count;j++)	//Vòng lặp for lặp count + 1 lần
		for (k=0;k<=5;k++);	//Vòng lặp con, lặp (count +1)*6 lần
}
void main()	//Hàm main chương trình
{
	
	v1=v2=v3=v4=v0=v5=v6=0;	//Khởi tạo các biến có giá trị ban đầu bằng 0
	//Gía trị trong while là 0 khi ko có điện, 1 khi có điện
	while(1)	//Vòng lặp while đc thực hiện khi giá trị bằng 1 (có điện)
	{   
		{
      			//Mỗi lần lặp sẽ thưc hiện tất cả công việc sau từ trên xuống dưới ( dòng 26 -> 105 )
			v0=v0+1; 	//Tăng v0 lên 1 đơn vị
			if(v0==130)	//Kiểm tra v0, nếu v0 = 130 thì tăng v1, reset v0. Nếu v0 ko bằng 130 thì bỏ qua dòng 28 -> 31
			{
				v0=0;
				v1=v1+1;
			}
			//Đoạn này là gán các giá trị, chuyên ngành điện t ko hiểu
			P2=0xFF;
			d = 1;
			d3 = d2 = d4 = d0 = d1= 0;
			P2 = arr[v1];
    	delay(msec);    //Gọi hàm delay ở dòng 11 -> 16
			if(v1==10)  //Kiểm tra nếu v1 = 10 thì reset v1 và tăng v2 lên 1 đơn vị, nếu v1 ko bằng 10 thì bỏ qua dòng 39 -> 42
			{
				v1=0;
				v2=v2+1;
			}
      //Đoạn này là gán các giá trị, chuyên ngành điện t ko hiểu
			P2=0xFF;
			d0 = 1;
			d4 = d3 = d1 =d=d2= 0;
			P2 = arr[v2];
			delay(msec);   //Gọi hàm delay ở dòng 11 -> 16

			if(v2==6) //Kiểm tra nếu v2 = 6 thì reset v2 và tăng v3 lên 1 đơn vị, nếu v2 ko bằng 6 thì bỏ qua dòng 51 -> 54
			{
				v2=0;
				v3=v3+1;
			}
			P2=0xFF;
			d1 = 1;
			d2 = d4 = d3 =d=d0= 0;
			P2 = arr[v3];
			delay(msec);

			if(v3==10)  //Kiểm tra nếu v3 = 10 thì reset v3 và tăng v4 lên 1 đơn vị, nếu v3 ko bằng 10 thì bỏ qua dòng 62 -> 65
			{
				v3=0;
				v4=v4+1;
			}
			P2=0xFF;
			d2 = 1;
			d3 = d4 = d1 =d=d0= 0;
			P2 = arr[v4];
			delay(msec);

			if(v4==6) //Kiểm tra nếu v4 = 6 thì reset v4 và tăng v5 lên 1 đơn vị, nếu v4 ko bằng 6 thì bỏ qua dòng 73 -> 76
			{
				v4=0;
				v5=v5+1;
			}
			P2=0xFF;
			d3 = 1;
			d0 = d2 = d1 =d=d4= 0;
			P2 = arr[v5];
			delay(msec);

			if(v5==10)  //Kiểm tra nếu v5 = 10 thì reset v5 và tăng v6 lên 1 đơn vị, nếu v5 ko bằng 10 thì bỏ qua dòng 84 -> 87
			{
				v5=0;
				v6=v6+1;
			}
			P2=0xFF;
			d4 = 1;
			d3 = d2 = d1 =d=d0= 0;
			P2 = arr[v6];
			delay(msec);
      
			if(v6==1&&v5==2)  //Kiểm tra giá trị v6 = 1 đồng thời v5 = 2, khi thỏa mãn cả 2 điều kiện sẽ reset v1 -> v6. Không thỏa mãn bỏ qua dòng 95->102
			{
				v1=0;
				v2=0;
				v3=0;
				v4=0;
				v5=0;
				v6=0;
			}
			delay(msec);
			P2=0xFF;
		}
	}
}
