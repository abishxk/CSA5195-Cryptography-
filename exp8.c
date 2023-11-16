//RSA exp 8

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
 
 int gcd(int n1,int e){
 	while ( e!= 0) {
        int temp = e;
        e = n1 % e;
        n1 = temp;
    }
    return n1;
 }
main(){
	int N,n,p,q,d,m;
	
	printf("Enter value two prime numbers :\n");
	scanf("%d %d",&p,&q);
	n=p*q;
	printf("n =%d\n",n);
	N=(p-1)*(q-1);
	printf("0n =%d\n",N);
	int n1=N;
	 int e = N;
    while (gcd(n1,e) != 1) {
        e++;
    }
	printf("e =%d\n",e);
	for(int i=1;i<=100000;i++){
		if(e*i % N == 1){
			d=i;
			break;
		}
	}
	printf("d =%d\n",d);
	printf("key :\n public={%d,%d}\nprivate={%d,%d}\n",e,n,d,n);
	printf("Enter a value for M(M<n) :");
	scanf("%d",&m);
	int x = pow(m,e);
	int c= x%n;
	printf("Encryption :\nC =%d\n",c);
	int y=pow(c,d);
	int D=y%n;
	printf("Decrytion :\nD =%d",D);
	
}