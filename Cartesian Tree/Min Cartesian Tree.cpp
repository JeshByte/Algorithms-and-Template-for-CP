    stack<ll> st;
    vector<ll> l(n,-1),r(n,-1);
    for(int i=0;i<n;i++){
        ll last=-1;
        while(!st.empty() && arr[st.top()]>arr[i]){
            last=st.top();
            st.pop();
        }
        if(last!=-1){
            l[i]=last;
        }
        if(!st.empty()){
            r[st.top()]=i;
        }
        st.push(i);
    }
    ll root;
    while(!st.empty()){
        root=st.top();
        st.pop();
    }
