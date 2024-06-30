
class DisjointSet{
    public : 

    vector<int> parent , size ;

    DisjointSet(int n){
        parent.resize(n+1) ;
        size.resize(n+1) ;

        for(int i = 0 ; i <= n ; i++){
            parent[i] = i ;
            size[i] = 1 ;
        }
    }

    int find(int u){
        if(parent[u] == u)
        return u ;

        return parent[u] = find(parent[u]) ;
    }

    bool merge_size(int u , int v){
        int p_u = find(u) ;
        int p_v = find(v) ;

        if(p_u != p_v){
            if(size[p_u] < size[p_v]){
                parent[p_u] = p_v ;
                size[p_v] = size[p_v] + size[p_u] ;
            }
            else{
                parent[p_v] = p_u ;
                size[p_u] = size[p_u] + size[p_v] ;
            }

            return true ;
        }

        return false ;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),greater<vector<int>>()) ;
        
        DisjointSet Alice = DisjointSet(n) ;
        DisjointSet Bob = DisjointSet(n) ;

        int connected_Alice = n , connected_Bob = n ;

        int count = 0 ;

        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][1] , v = edges[i][2] ;

            if(edges[i][0] == 3){
                bool Alice_join = Alice.merge_size(u,v) ;
                bool Bob_join = Bob.merge_size(u,v) ;

                if(!Alice_join && !Bob_join){
                    count++ ;
                }
                else if(!Alice_join){
                    connected_Bob-- ;
                }
                else if(!Bob_join){
                    connected_Alice-- ;
                }
                else{
                    connected_Alice-- ;
                    connected_Bob-- ;
                }
            }
            else if(edges[i][0] == 2){
                bool Bob_join = Bob.merge_size(u,v) ;
                if(!Bob_join){
                    count++ ;
                }
                else{
                    connected_Bob-- ;
                }
            }
            else if(edges[i][0] == 1){
                bool Alice_join = Alice.merge_size(u,v) ;
                if(!Alice_join){
                    count++ ;
                }
                else{
                    connected_Alice--;
                }
            }
        }
        //if any of these is not connected
        if(connected_Alice != 1 || connected_Bob != 1)
        return -1;

        return count ;
    }
};