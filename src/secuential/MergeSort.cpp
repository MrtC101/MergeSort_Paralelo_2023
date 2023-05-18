#include <list>
#include <math.h>

using namespace std;

class MergeSort{

    list<int>* merge(list<int>* left,list<int>* right){
        list<int> *L;
        list<int>::const_iterator i = left->cbegin();
        list<int>::const_iterator j = right->cbegin();
        while(i!=left->cend() || j!=right->cend()){
            if(i!=left->cend() && j!=right->cend()){
                if(*i<*j)
                    L->push_back(*i);
                    i++;
                }else{
                    L->push_back(*j);
                    j++;
                }
            }else if(i!=left->cend()){
                L->push_back(*i);
                i++;
            }else {
                L->push_back(*j);
                j++;
            }
        }
        return L
    }


    list<int> *mergeSort(list<int> * L){
        list<int>::iterator middle = next(L->begin(),floor(L->size()/2)); 
        list<int> *left = new list<int>(L->begin(),middle);
        list<int> *right = new list<int>(middle,L->end());
        mergeSort(left);
        mergeSort(right);
        return merge(left,right)
    }

    static list<int>* sort(list<int> * L){
        MergeSort *obj = new MergeSort();
        (*obj).mergeSort(L);
        return L;
    }

};