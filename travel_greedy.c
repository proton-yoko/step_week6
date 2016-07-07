//Nとファイル名を書き換えると使える
//yokokato

#include <stdio.h>
#include <math.h>

#define N 2048//このNを変化させる

double x[N],y[N];
int root[N];
double mindis;
double point_dis[N][N];

double distance(int i, int j){
    //２点の距離
	double dis;
	double xlen = x[i]-x[j];
	double ylen = y[i]-y[j];
	dis = sqrt(xlen * xlen + ylen * ylen);
	return dis;
}

double sum_distance(int* root){
    //どれくらい移動するか
    int i;
	double sum=0;
    sum += point_dis[root[N-1]][0];
    for(i=0; i<N-1; i++){
        sum += point_dis[root[i]][root[i+1]];
        //if(sum > mindis) break;
    }

	return sum;
}

void calculate_distance(){
    int i,j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(i != j){
                point_dis[i][j] = distance(i, j);
            }
        }
    }
    
}

void solve_loop(int* visited, int places){
    
    root[0]=0;
    
    int i;
    double this_dis;
    
    
    if(places == N-2){
        for(i=1; i<N; i++){
            if(visited[i]==0){
                places ++;
                root[places]=i;
                
            
                this_dis=sum_distance(root);
                if(this_dis < mindis){
                   
                    mindis = this_dis;
                   // for(int j=0; j<N; j++){
                     //   printf("%d ",root[j]);
                    //}
                    printf("%lf\n", mindis);
                }
                places--;
            }
        }
    }else{
        for(i=1; i<N; i++){
            if(visited[i]==0){
                places++;
                root[places]=i;
                
                visited[i]=1;
                solve_loop(visited, places);
                visited[i]=0;
                places--;
            }
        }
        
    }
    
}

void solve(){
    
    int i;
    int visited[N], places=0;
    
    //root[0]=0;
    
    //visited[i]:if i is visited, 1
    //			:if not,          0
    for(i=0; i<N; i++){
        visited[i]=0;
        root[i]=i;
    }
    
    
    mindis = sum_distance(root);
    
    solve_loop(visited, places);
    
    
}

void solve_greedy(){
	int i, j, k, counter;
	int visited[N], places=0, this_place;
	double mindis;
	double sum=0;
	double sum_min;

	for(i=0; i<N; i++){
		visited[i]=0;
		root[i]=i;
	}

	int pre = 0;//一個前の場所を記憶

	for(j=0; j<N; j++){

		for(k=0; k<N; k++){
			visited[k]=0;
		}
		pre = j;
		places=1;
		sum = 0;
		visited[j]=1;
		while(places<N){
			counter = 0;
			for(i=0; i<N; i++){
				if(visited[i]==0){
					if(counter==0){
						mindis = point_dis[pre][i];
						this_place = i;
						counter=1;
					}else{
						if(point_dis[pre][i]<mindis){
							mindis = point_dis[pre][i];
							this_place = i;
						}
					}
				}
			}
			//printf("%d\n", this_place);
			pre = this_place;
			sum += mindis;
			places ++;
			visited[this_place]=1;
		}
		sum += point_dis[this_place][j];
		if(j==0){
			sum_min = sum;
		}
		if(sum < sum_min){
			sum_min = sum;
			printf("greedy for start=%d is %lf\n",j,sum_min);
		}
		//printf("mindistance = %lf\n", sum);
	}


}

int main(void){

	FILE *fp;
	char *fname = "input_6.csv";//ファイルも書き換える
	int i;
	char xchar, ychar;

	fp = fopen(fname, "r");
	if(fp == NULL){
		printf("%sファイルが開けません\n",fname);
		return -1;
	}

	fscanf(fp, "%c,%c", &xchar, &ychar);

	for(i=0; i<N; i++){
		fscanf(fp, "%lf,%lf", &x[i], &y[i]);
		printf("%lf , %lf\n", x[i], y[i]);
	}
 
    calculate_distance();
    
    solve_greedy();
    
	fclose(fp);
	return 0;
}
