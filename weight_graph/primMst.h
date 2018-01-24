#include<iostream>
#include<vector>
#include<cassert>


template <typename Graph, typename Weight>
class PrimMst{
private:
    Graph &G;
    vector<Edge<Weight>*> edgeto;  //算法辅助数据结构，访问的点对应的边
    IndexMInHeap<Weight> ipq;       //最小搜索堆
    bool *marked;                   //标记数组
    vector<Edge<Weight> > mst;      //存放权值最小的边
    Weight weight;


    void visit(int v){

        assert(!marked[v]);
        marked[v] = true;

        typename adjIterator::adj(G,v);
        for(Edge<Weight>* e = adj.begin(); !adj.end();e = adj.next()){
            int w = e->other(v);
            if(!marked[w]){
                if(!edgeto[w]){
                    edgeto[w] = e;
                    ipq.insert(w,e->wt());
                }
                else if(edgeto[w]->wt() > e->wt()){
                    edgeto[w] = e;
                    ipq.change(e,e->wt());
                }
            }
        }
    }
public:
    PrimMst(Graph &graph):G(graph),ipq(IndexMinHeap<double>(0,graph.V())){

        assert(graph.V() >= 1);
        marked = new bool[graph.V()];
        for(int i = 0 ; i < graph.V();i++ ){
            mared[i] = false;
            edgeto[i].push_back(NULL);
        }

        mst.clear();

        visit(0);
        while( !ipq.empty() ){

            int v = ipq.extractMinIndex();
            assert( edgeto[v] );

            mst.push_back(*edgeto[v]);
            visit(v);
        }
        mstWeight = mst[0].wt();
        for( int i = 1 ; i < mst.size() ; i ++ )
            mstWeight += mst[i].wt();

    }

    ~PrimMST(){
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges(){
        return mst;
    };

    Weight result(){
        return mstWeight;
    };

};