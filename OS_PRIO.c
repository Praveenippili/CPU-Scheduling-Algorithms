#include<stdio.h>
struct set{
	int p,a,b,c,bc,pr;
}t;
int main(){
	int n,ln,rn = 0,fn = 0,te,j,i,pri;
	float tatsum = 0,wtsum = 0;
	printf("Enter number of processes:");
	scanf("%d",&n);
	printf("Enter 1 if highest number represents highest priority\nEnter 0 if lowest number represents highest priority\n");
	printf("Enter number which defines the priority:");
	scanf("%d",&pri);
	ln = n;
	struct set l[n],r[n],f[n];
	for(i = 0;i < n;i++){
		printf("Enter process %d Arrival time ,burst time and priority:",(i + 1));
		scanf("%d %d %d",&l[i].a,&l[i].b,&l[i].pr);
		l[i].p = i + 1;
		l[i].bc = l[i].b;
	}
	for(i = 0;i < n;i++){
		for(j = i+1;j<n;j++){
			if(l[i].a > l[j].a){
				t = l[i];
				l[i] = l[j];
				l[j] = t;		
			}
		}
	}
	te = l[0].a;
	r[rn] = l[0];
	rn++;
	for(i = 0;i < (n - 1);i++){
		l[i] = l[i+1];
	}
	ln--;
	
	while(fn < n){
		for(i = 0;i < ln;i++){
			if(l[i].a <= te){
				r[rn] = l[i];
				rn++;
				for(j = i;j < (ln - 1);j++){
					l[j] = l[j+1];
				}
				ln--;
				i--;
			}
		}
		if(pri == 0){
			for(i = (rn-1);i >= 0;i--){
				for(j = i-1;j >= 0;j--){
					if(r[i].pr < r[j].pr){
						t = r[i];
						r[i] = r[j];
						r[j] = t;
					}
				}
			}
		}
		if(pri == 1){
			for(i = (rn-1);i >= 0;i--){
				for(j = i-1;j >= 0;j--){
					if(r[i].pr > r[j].pr){
						t = r[i];
						r[i] = r[j];
						r[j] = t;
					}
				}
			}	
		}
		
		if(r[0].a <= te){
			te += 1;
		}
		else{
			te = r[0].a + 1;
		}
		r[0].bc -= 1;
		if(r[0].bc == 0){
			r[0].c = te;
			f[fn] = r[0];
			fn++;
			for(j = 0;j < (rn - 1);j++){
				r[j] = r[j+1];
			}
			rn--;
		}
		
		
	}
	for(i = 0;i < n;i++){
		for(j = i+1;j<n;j++){
			if(f[i].p > f[j].p){
				t = f[i];
				f[i] = f[j];
				f[j] = t;		
			}
		}
	}
	printf("Pid\tAt\tBt\tP\tCT\tTAT\tWT\n");
	for(i = 0;i < fn;i++){
		printf ("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",f[i].p,f[i].a,f[i].b,f[i].pr,f[i].c,te = (f[i].c-f[i].a),ln = (f[i].c-f[i].a-f[i].b));
		tatsum += te;
		wtsum += ln; 
	}
	printf("Average turn around time:%f\nAverage waiting time:%f",(tatsum/n),(wtsum/n));
}

