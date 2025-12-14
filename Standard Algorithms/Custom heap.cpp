struct Compare {
    bool operator()(const pair<ll,ll>& a, const pair<ll,ll>& b) {
        if(a.first!=b.first){
            return a.first < b.first;
        }
        else{
            return a.second > b.second;
        }
    }
};
int main(){
  priority_queue<ll,vector<ll>,Compare) pq;
}
