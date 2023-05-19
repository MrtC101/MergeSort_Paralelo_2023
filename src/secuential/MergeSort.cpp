#include <list>
#include <math.h>
using namespace std;

class MergeSort{
    public:
    static list<int>* sort(list<int> * L){
        MergeSort *obj = new MergeSort();
        (*obj).mergeSort(L);
        return L;
    }
    static void print(list<int>* L){
        cout << "[";  
        for(list<int>::const_iterator it = L->cbegin(); it != L->cend(); it++){
            cout << *it;
            if(&*it != &*L->crbegin()){
                cout << ",";
            }
        }                                                                       
        cout << "]" << endl;                                              
    }
    private:

    void merge(list<int> *L,list<int>* left,list<int>* right){
        list<int>::iterator i = left->begin();
        list<int>::iterator j = right->begin();
        while(i != left->end() || j != right->end()){
            if(j != right->end() && i != left->end()){
                if(*i == *j || *i < *j){
                    L->push_back(*i);
                    L->pop_front();
                    left->pop_front();
                    i = left->begin();
                }
                if(*i == *j || *i > *j){
                    L->push_back(*j);
                    L->pop_front();
                    right->pop_front();
                    j = right->begin();
                }
            }else if(j != right->end()){
                L->push_back(*j);
                L->pop_front();
                right->pop_front();
                j = right->begin();
            }else if(i != left->end()){
                L->push_back(*i);
                L->pop_front();
                left->pop_front();
                i = left->begin();
            }
        }
    }

    
    void mergeSort(list<int> * L){
        if(L->size()>1){
        list<int>::iterator middle = next(L->begin(),floor(L->size()/2)); 
        list<int> *left = new list<int>(L->begin(),middle);
        list<int> *right = new list<int>(middle,L->end());
        mergeSort(left);
        mergeSort(right);
        merge(L,left,right);
        }
    }
};