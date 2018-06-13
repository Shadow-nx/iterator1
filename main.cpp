#include <iostream>
#include "tree.hpp"

using namespace BSTree;

int main(){
    //Tree<int> tree = {5, 3, 4, 2, 7, 0, 9, 6, 8 , 1,-5,-10,-1,-2,-3,-4,-6,-7,-8,-9,10};
    Tree<int> tree ={20,15,0,1,4,3,2,6,7,8,30,22,23,24,31,32,33,34,21};
    auto it = tree.begin();
    auto it1 = tree.begin();
    auto end = tree.end();
    tree.show();
    cout<<endl;
    cout<<endl;
    tree.balance(it,it1,end);
    tree.show();
    /*
    auto rit = tree.rbegin();
    auto rit1 = tree.rbegin();
    auto rend = tree.rend();
    cout<<*rit<<" ";
    tree.show();
    

    
    for(;rit!=rend;++rit){
        cout<<*rit<<" ";
    }
    cout<<endl;
    --rit;
    for(;rit!=rit1;--rit){
       cout<<*rit<<" "; 
    }
    cout<<endl;
    ++rit;
    for(;rit!=rend;++rit){
        cout<<*rit<<" ";
    }
    cout<<endl;
    --rit;
    for(;rit!=rit1;--rit){
       cout<<*rit<<" "; 
    }
    tree.show();
*/
return 0;
}
