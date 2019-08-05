#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

double get_local_max(double w,double a,double s){

	return sqrt(((w * w) + (2 * a * s)) / 2) ;
	
}

double get_time(double v0, double vt, double a){
	
	return (vt - v0) / a ;
	
}

double get_end_speed(double v0, double a, double s){
	
	return sqrt((v0 * v0) + (2 * a * s)) ;
	
}

double get_distance(double v0, double vt, double a){
	
	return ((vt * vt) - (v0 * v0)) / (2 * a);
	
}

int main(){
	
	double v,a;
	double l,d,w;
	
	scanf("%lf %lf",&a,&v);
	scanf("%lf %lf %lf",&l,&d,&w);
	
	double t = 0;
	
	double v_max = get_end_speed(0, a, d);
	//printf("v_max: %lf\n",v_max);
	
	if ( v_max > w && v > w){
		
		double v_local_max = get_local_max(w,a,d);
		//printf("v_local_max: %lf\n",v_local_max);
		
		if(v_local_max > v){
			double s1 = get_distance(0,v,a);
			double s3 = get_distance(v,w,-a);
			double s2 = d - s1 - s3;
			
			//printf("s1: %lf S2: %lf S3: %lf\n",s1,s2,s3);
			
			t += get_time(0,v,a);
			//printf("%lf\n",t);
			t += (s2 / v);
			//printf("%lf\n",t);
			t += get_time(v,w,-a);
			//printf("%lf\n",t);
			
		}
		else{
			t += get_time(0,v_local_max,a);
			
			//printf("%lf\n",t);
			t += get_time(v_local_max,w,-a);
			//printf("%lf\n",t);
			//printf("%lf %lf\n",get_distance(0,v_local_max,a),get_distance(v_local_max,w,-a));

		}
		
		v_max = w;
		
	}
	else if(v_max > w && w >= v){
		double s1 = get_distance(0,v,a);
		double s2 = d - s1;

		t += get_time(0,v,a);
		t += (s2 / v);

		v_max = v;
	}
	else if(v_max <= w && v > w){
		
		t += get_time(0,v_max,a);
		
	}
	else if(v_max <= w && v <= w){
		if(v_max <= v){
			t += get_time(0,v_max,a);
		}
		else{
			double s1 = get_distance(0,v,a);
			double s2 = d - s1;

			t += get_time(0,v,a);
			t += (s2 / v);

			v_max = v;
		}
	}
	
	
	
	double v_end_max = get_end_speed(v_max, a, l - d);
	
	//printf("%lf vmax %lf\n",t, v_max);
	
	if(v_end_max > v){
		double s1 = get_distance(v_max,v,a);
		double s2 = l - d - s1;
		t += get_time(v_max,v,a);
		//printf("%lf\n",t);
		t += (s2 / v);
		//printf("%lf\n",t);
	}
	else{
		t += get_time(v_max,v_end_max,a);
	}
	
	printf("%lf\n",t);

	
	return 0;
}