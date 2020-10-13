#include<bits/stdc++.h>
using namespace std;
struct inter_state
{
    vector<queue<int>>adj;
 
};
inter_state goal;
// void display(int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         while(!goal.adj[i].empty())
//         {
//             cout<<goal.adj[i].front();
//             goal.adj[i].pop();
//         }
//         cout<<endl;
//     }
// }
int heuristic(vector<queue<int>>src,int n)
{
    int c=0;
    for(int i=0;i<n;i++)
    {   
       
       
        
       unordered_map<int,int>b1;
        b1.clear();
         vector<queue<int>>q = goal.adj;
        while(!q[i].empty())
        { 
            b1[q[i].front()]++;
            q[i].pop();
        }
        while(!src[i].empty())
        {
            if(b1.find(src[i].front())==b1.end())c+=2;
            src[i].pop();
        }
       }
     
    return c;
}
map<vector<queue<int>>,int>cost;
map<vector<queue<int>>,bool>visited;
map<vector<queue<int>>,string>path;
struct cmp { 
    bool operator()(const pair<int,vector<queue<int>>>&p1 ,const pair<int,vector<queue<int>>>&p2) { 
        if(p1.first>p2.first)return true;
        if(p1.first==p2.first)return !(path[p1.second]>path[p2.second]);
         if(p1.first<p2.first)return false;
         
       
        } 
};
 
void Astart(vector<queue<int>>src,int n)
{
    cost.clear();
    path.clear();
    cost[src]=0;
    visited[src]=false;
    visited.clear();
    priority_queue<pair<int,vector<queue<int>>>,vector<pair<int,vector<queue<int>>>>,cmp>pq;
    pq.push(make_pair(0,src));
    int y=0;
    bool flag = true;
    while(!pq.empty())
    {
        pair<int,vector<queue<int>>>parent = pq.top();
        pq.pop();
        if(parent.second==goal.adj)
        {
            cout<<path[parent.second];
            flag = true;
            break;
        }
        if(visited[parent.second]==false)
        {
            visited[parent.second]=true;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {   vector<queue<int>>child = parent.second;
                    if(!(child[i].empty()))
              { 
                   string s1="";
                 string s2="";
                  int x = child[i].front();
                  child[i].pop();
                  child[j].push(x);
                   s1="remove out "+to_string(x)+" from "+to_string(i);
               s2="insert "+to_string(x)+" in "+to_string(j);
 
                                y = heuristic(child,n);
                                   string vect=path[parent.second];
                                  
              if(cost.find(child)==cost.end())
              {  
                  cost[child]=cost[parent.second]+2;
                   
 
                  pq.push(make_pair(y+(cost[parent.second]+2),child));
                  path[child]="";
                  if(vect.length()!=0)path[child]+= ("\n"+vect+"\n");
                 path[child]+=(s1+"\n"+s2); 
                 }
              if(((cost[child]))>(cost[parent.second]+2))
              {
                  cost[child]=cost[parent.second]+2;
                   
 
                  pq.push(make_pair(y+(cost[parent.second]+2),child));
                  path[child]="";
                  if(vect.length()!=0)path[child]+= ("\n"+vect+"\n");
                 path[child]+=(s1+"\n"+s2);
              }
            
             else if((((cost[child]))==((cost[parent.second]+2))))
              {
                    string s = path[child];
                    string a="";
                     if(vect.length()!=0)a+=  ("\n"+vect+"\n");
                      a+=(s1+"\n"+s2);
                    if(a<s)
                    {
                    cost[child]=cost[parent.second]+2;
 
                  
 
                 pq.push(make_pair(y+(cost[parent.second]+2),child));
                     path[child]=a;
                    }
              
                
              }
 
             
 
            //   else if(v.find(h)!=v.end() && ((y+(v[h]))>=(y+(v[parent->adj]+2))))
            //   {v[h]=v[parent->adj]+2;
            //   inter_state*child = new inter_state(h,(y)+(v[h]),false);
 
            //       q.push(child);
            //      mp[h]="";
            //      if(vect.length()!=0)mp[h]+=  ("\n"+vect+"\n");
            //      mp[h]+=(s1+"\n"+s2);
            //   }
              }
             
                }
            }
        }
 
    }
    if(!flag)
    cout<<"-1\n";
 
}
 
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<queue<int>>intial(n);
        vector<queue<int>>g(n);
        int cap,x;
        for(int i=0;i<n;i++)
        {
            cin>>cap;
            for(int j=0;j<cap;j++)
            {
                cin>>x;
                intial[i].push(x);
            }
        }
        for(int i=0;i<n;i++)
        {
            cin>>cap;
            for(int j=0;j<cap;j++)
            {
                cin>>x;
                g[i].push(x);
            }
        }
        goal.adj = g;
        Astart(intial,n);
 
    }
}
