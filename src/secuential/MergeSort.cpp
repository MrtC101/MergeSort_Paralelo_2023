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
        std::cout << "[";  
        for(list<int>::const_iterator it = L->cbegin(); it != L->cend(); it++){
            std::cout << *it;
            if(&*it != &*L->crbegin()){
                std::cout << ",";
            }
        }                                                                       
        std::cout << "]" << std::endl;                                              
    }
    private:

    void merge(list<int> *L,list<int>* left,list<int>* right){
        list<int>::iterator i = left->begin();
        list<int>::iterator j = right->begin();
        while(i != left->end() || j != right->end()){
            if(i != left->end() && j != right->end()){
                if(*i<*j){
                    //L->insert(*i,L->end());
                    L->push_back(*i);
                    left->pop_front();
                    i++;
                }else{
                    L->push_back(*j);
                    right->pop_front();
                    j++;
                }
            }else if(i!=left->cend()){
                L->push_back(*i);
                left->pop_front();
                i++;
            }else {
                L->push_back(*j);
                right->pop_front();
                j++;
            }
        
        }
    }

    
    void mergeSort(list<int> * L){
        if(L->size()>1){
        list<int>::iterator middle = next(L->begin(),floor(L->size()/2)); 
        list<int> *left = new list<int>(L->begin(),middle);
        list<int> *right = new list<int>(middle,L->end());
        print(right);
        mergeSort(left);
        mergeSort(right);
        merge(L,left,right);
        }
    }
};