#include "node.hpp"
using namespace std;

namespace BSTree {

    template<typename T>
    class iterator;

    template <typename T>
    class pre_iterator;

    template <typename T>
    class post_iterator;

    template<typename T>
    class iterator {

        using pointer = T *;
        using reference = T &;
        using value_type = T;

    public:
        iterator(){
            ptr=nullptr;
        }

    private:
        Node<T>* ptr;
    };
    

    template <typename T>
    class pre_iterator : iterator<T> {
    public:
        pre_iterator();
        pre_iterator(Node<T>* ptr);
        auto operator *() -> T&;
        auto operator--() -> pre_iterator<T>&;
        auto operator++() ->pre_iterator<T>&;
        auto simetryc() -> bool;
        template <typename T2>
        friend auto operator!=(pre_iterator<T2>& lhs, pre_iterator<T2>& rhs) -> bool{
            if(lhs.node!=rhs.node)
                return true;
            else
                return false;
        }
    private:
        Node<T>* node;
    };

    template <typename T>
    class post_iterator : iterator<T> {
    public:
        post_iterator();
        post_iterator(Node<T>* ptr);
        auto operator *() -> T&;
        auto operator--() -> post_iterator<T>&;
        auto operator++() ->post_iterator<T>&;
        auto simetryc() -> bool;
        template <typename T2>
        friend auto operator!=(post_iterator<T2>& lhs, post_iterator<T2>& rhs) -> bool{
            if(lhs.node!=rhs.node)
                return true;
            else
                return false;
        }
    private:
        Node<T>* node;
    };

    template <typename T>
    post_iterator<T>::post_iterator(){
        node=nullptr;
    }
    template <typename T>
    post_iterator<T>::post_iterator(Node<T>* ptr){
        node=ptr;
    }
    template <typename T>
    auto post_iterator<T>::operator *() -> T&{
        if(node!=nullptr){
            if(node->data!=nullptr)
                return *(node->data);
        }
    }
    template <typename T>
    auto post_iterator<T>::operator++() -> post_iterator<T>&{
        if(node->data==nullptr)
            node->test=true;
            while(true){
                if(node->parent==nullptr){
                    if(node->left!=nullptr && node->left->test==false){
                        node=node->left;
                        if(node->right!=nullptr && node->right->test==false)
                            continue;
                        else{
                            //node->test=false;
                            break;
                        }
                    }
                }else if(node==node->parent->right){
                    if(node->left!=nullptr && node->left->test==false){
                        node=node->left;
                        if(node->right!=nullptr && node->right->test==false)
                            continue;
                        else{
                            //node->test=false;
                            break;
                        }
                    }else if((node->left==nullptr || (node->left!=nullptr && node->left->test==true)) && node->parent!=nullptr){
                        if(node->parent!=nullptr)
                            node=node->parent;
                        //node->test=false;
                        break;
                    }
                }else if(node==node->parent->left){
                    if(node->right!=nullptr && node->right->test==false){
                        while(node->right!=nullptr && node->right->test==false){
                            node=node->right;
                        }
                        break;
                    }else if((node->right==nullptr || node->right!=nullptr) && node->left!=nullptr && node->left->test==false){
                        node=node->left;
                        if(node->right!=nullptr)
                            continue;
                        else{
                            //node->test=false;   
                            break;
                        }
                    }else{
                        if(node->parent!=nullptr)
                            node=node->parent;
                        continue;
                    }
                    break;
                }
            }
            node->test=true;                
            return *this; 
    }
    template <typename T>
    auto post_iterator<T>::operator--() ->post_iterator<T>&{
        if(node->data==nullptr)
            node->test=false;
        while(true){
            if(node->parent==nullptr){
                if(node->right!=nullptr && node->right->test==true){
                    node=node->right;
                    continue;
                }else if(node->right==nullptr){
                    {
                    //node->test=true;
                    break;
                    }
                }
            }else if(node==node->parent->left){
                if(node->right!=nullptr && node->right->test==true)
                {
                    node=node->right;
                    if(node->left!=nullptr)
                        continue;
                    else{
                        //node->test=true;
                        break;
                    }
                }else if((node->right==nullptr || (node->right!=nullptr && node->right->test==false))&&node->parent!=nullptr){
                    if(node->parent!=nullptr)
                        node=node->parent;
                    //node->test=true;
                    break;
                }
                break;
            }else if(node==node->parent->right){
                if(node->left!=nullptr && node->left->test==true){
                    while(node->left!=nullptr && node->left->test==true){
                        node=node->left;
                    }
                    //node->test=true;
                    break;
                }else if((node->left==nullptr || node->left!=nullptr) && node->right!=nullptr && node->right->test==true){
                    node=node->right;
                    if(node->left!=nullptr)
                        continue;
                    else{
                        //node->test=true;
                        break;
                    }
                }else{
                    if(node->parent!=nullptr)
                        node=node->parent;
                    continue;
                }
            }
        }
        node->test=false;
        return *this; 
        }  
    template <typename T>
    pre_iterator<T>::pre_iterator(){
        node=nullptr;
    }

    template <typename T>
    pre_iterator<T>::pre_iterator(Node<T>* ptr){
        node=nullptr;
        node=ptr;
    }
    template <typename T>
    auto simetryc() -> bool{
        
    }
    
    template <typename T>
    auto pre_iterator<T>::operator *() -> T&{
        if(node!=nullptr){
            if(node->data!=nullptr)
                return *(node->data);
        }
    }
    template <typename T>
    auto pre_iterator<T>::operator--() -> pre_iterator<T>&{
            if(node->data==nullptr)
                node->test=false;
            while(true){
                if(node->parent==nullptr){
                    if(node->left!=nullptr && node->left->test==true){
                        node=node->left;
                        if(node->right!=nullptr && node->right->test==true)
                            continue;
                        else{
                            node->test=false;
                            break;
                        }
                    }
                }else if(node==node->parent->right){
                    if(node->left!=nullptr && node->left->test==true){
                        node=node->left;
                        if(node->right!=nullptr && node->right->test==true)
                            continue;
                        else{
                            node->test=false;
                            break;
                        }
                    }else if((node->left==nullptr || (node->left!=nullptr && node->left->test==false)) && node->parent!=nullptr){
                        if(node->parent!=nullptr)
                            node=node->parent;
                        node->test=false;
                        break;
                    }
                }else if(node==node->parent->left){
                    if(node->right!=nullptr && node->right->test==true){
                        while(node->right!=nullptr && node->right->test==true){
                            node=node->right;
                        }
                        node->test=false;
                        break;
                    }else if((node->right==nullptr || node->right!=nullptr) && node->left!=nullptr && node->left->test==true){
                        node=node->left;
                        if(node->right!=nullptr)
                            continue;
                        else{
                            node->test=false;   
                            break;
                        }
                    }else{
                        if(node->parent!=nullptr)
                            node=node->parent;
                        continue;
                    }
                    break;
                }
            }
            node->test=false;                
            return *this; 
    }
    template <typename T>
    auto pre_iterator<T>::operator++() ->pre_iterator<T>&{
        if(node->data==nullptr)
            node->test=true;
        while(true){
            if(node->parent==nullptr){
                if(node->right!=nullptr && node->right->test==false){
                    node=node->right;
                    continue;
                }else if(node->right==nullptr){
                    {
                    node->test=true;
                    break;
                    }
                }
            }else if(node==node->parent->left){
                if(node->right!=nullptr && node->right->test==false)
                {
                    node=node->right;
                    if(node->left!=nullptr)
                        continue;
                    else{
                        node->test=true;
                        break;
                    }
                }else if((node->right==nullptr || (node->right!=nullptr && node->right->test==true))&&node->parent!=nullptr){
                    if(node->parent!=nullptr)
                        node=node->parent;
                    node->test=true;
                    break;
                }
                break;
            }else if(node==node->parent->right){
                if(node->left!=nullptr && node->left->test==false){
                    while(node->left!=nullptr && node->left->test==false){
                        node=node->left;
                    }
                    node->test=true;
                    break;
                }else if((node->left==nullptr || node->left!=nullptr) && node->right!=nullptr && node->right->test==false){
                    node=node->right;
                    if(node->left!=nullptr)
                        continue;
                    else{
                        node->test=true;
                        break;
                    }
                }else{
                    if(node->parent!=nullptr)
                        node=node->parent;
                    continue;
                }
            }
        }
        node->test=true;
        return *this; 
    }  
}
