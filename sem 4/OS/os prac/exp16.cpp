
//code by sneha gupta 2021UCA1859

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,i,j,k;
    cout<<"Enter number of frames\n";
    cin>>n;
    cout<<"Enter number of processes\n";
    cin>>m;
    vector<int> p(m);
    cout<<"Enter processes\n";
    for(i=0;i<m;i++){
        cin>>p[i];
    }
    vector<vector<int>> a(n,vector<int>(m,-1));
    map <int, int> mp,lfmp;    
    for(i=0;i<m;i++){
        vector<int> op;
        vector<pair<int,int>> c,lf;
        for(auto q: mp){
            c.push_back({q.second,q.first});
        }
        for(auto q:lfmp){
            lf.push_back({q.second,q.first});
        }
        sort(lf.begin(),lf.end());
        bool dontCall=true;    
        if(lf.size()>2){
            if(lf[0].first!=lf[1].first){
                dontCall=false;        
            }
        }
        sort(c.begin(),c.end());
        bool hasrun=false;
        for(j=0;j<n;j++){
            if(a[j][i]==p[i]){
                mp[p[i]]++;
                lfmp[p[i]]++;
                hasrun=true;
                break;
            }
            if(a[j][i]==-1){
                for(k=i;k<m;k++)
                    a[j][k]=p[i];
                mp[p[i]]++;
                lfmp[p[i]]++;
                hasrun=true;
                break;
            }
        }
        if(j==n||hasrun==false){
            for(j=0;j<n;j++){
                if(dontCall==true){
                    int q;
                    if(lf[lf.size()-1].second==c[c.size()-1].second&&lf[lf.
size()-1].first>1){
                        if(a[j][i]==c[c.size()-2].second){
                        mp.erase(a[j][i]);
                        lfmp.erase(a[j][i]);
                        for(k=i;k<m;k++)
                            a[j][k]=p[i];
                        mp[p[i]]++;
                        lfmp[p[i]]++;
                        break;
                        }
                    
                    }
                else{
                    if(a[j][i]==c[c.size()-1].second){
                        mp.erase(a[j][i]);
                        lfmp.erase(a[j][i]);
                        for(k=i;k<m;k++)
                            a[j][k]=p[i];
                        mp[p[i]]++;
                        lfmp[p[i]]++;
                        break;
                    }
                    }
                }
                else if(dontCall==false){
                    if(a[j][i]==lf[0].second){
                        mp.erase(a[j][i]);
                        lfmp.erase(a[j][i]);
                        for(k=i;k<m;k++)
                            a[j][k]=p[i];
                        mp[p[i]]++;
                        lfmp[p[i]]++;
                        break;
                    }
                }
            }
        }
        for(auto q:mp){
            if(q.first!=p[i]){
                mp[q.first]++;
            }
        }
    }
    int hit=0;
    vector<int> hitv(m);
    for(i=1;i<m;i++){
        for(j=0;j<n;j++){
            if(p[i]==a[j][i-1]){
                hit++;
                hitv[i]=1;
                break;            
            }
        }
    }
    cout<<"Process ";
    for(i=0;i<m;i++){
        cout<<p[i]<<" ";
    }
    cout<<'\n';
    for(i=0;i<n;i++){
        cout<<"Frame "<<i<<" ";
        for(j=0;j<m;j++){
            if(a[i][j]==-1)
                cout<<"E ";
                else
            cout<<a[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<"HIT ";
    for(i=0;i<hitv.size();i++){
        if(hitv[i]==0)
            cout<<" ";
        else
        cout<<hitv[i]<<" ";
    }
    cout<<"\n";
    cout<<"Hit "<<hit<<'\n'<<"Page Fault "<<m-hit<<'\n';
    return 0;
}