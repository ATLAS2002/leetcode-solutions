class Solution {
private:
    double timeRequired(vector<int>& dist, int speed) {
        int n = dist.size();
        double time = 0;
        for(int i=0; i<n-1; i++) 
            time += ceil(dist[i]*1.0/speed); 
        time += (dist[n-1]*1.0/speed); 
        return time;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour <= n-1) return -1; 
        int mn = 1, mx = 1e7;
        while(mn < mx) {
            int speed = mn + (mx-mn)/2;
            double time = timeRequired(dist, speed);
            if(time <= hour) mx = speed;
            else mn = speed+1;
        }   return mx;
    }
};