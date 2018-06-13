#include "iterator.hpp"
#include <iostream>
#include <vector>

using namespace std;

namespace BSTree {
template <typename T>
    class Tree {
    public:
       // using iterator = pre_order::iterator;
        //using reverse_iterator = post_order::iterator;

        Tree(std::initializer_list<T>);

        auto balance(pre_iterator<T>& it,pre_iterator<T>& it1,pre_iterator<T>& end) -> Tree<T>&;
        auto balance(vector<T>& elements,T count,T count1) -> void;
        auto push_back(Node<T>*&,Node<T>*&,const T&) -> Node<T>*;
        auto show() -> void;
        auto show(Node<T>* root,T data)const -> void;
        auto test(pre_iterator<T>& it1,pre_iterator<T>& it,pre_iterator<T>& end) -> void;
        auto delete_tree(Node<T>*&node) -> void;
        auto delete_tree() -> void;

        auto begin() -> pre_iterator<T>;
        auto end() -> pre_iterator<T>;

        auto rbegin() -> post_iterator<T>;
        auto rend() -> post_iterator<T>;

    private:
        Node<T>* root;
        T value;
    };
    
    template <typename T>
    Tree<T>::Tree(std::initializer_list<T> list){
            value=0;
            root = nullptr;
            for(auto i : list){
                push_back(root,root,i);
        }
    }
    template <typename T>
    auto Tree<T>::delete_tree(Node<T>*&node) -> void {
	if(node != nullptr) {
		delete_tree(node->left);
		delete_tree(node->right);
		if(node->data!=nullptr)
		    delete node->data;
		delete node;
		node = nullptr;
	    }
    }
    template <typename T>
    auto Tree<T>::delete_tree() -> void{
        delete_tree(root);
    }
    template <typename T>
    auto Tree<T>::balance(vector<T>& elements,T count,T count1) -> void{
        push_back(root,root,elements[count+count1]);
        push_back(root,root,elements[count-count1]);
        if(count1/2>=1){            
            if(count1%2==0){
                balance(elements,count+count1,count1/2);
                balance(elements,count-count1,count1/2);
            }else{
                balance(elements,count+count1,count1/2);
                balance(elements,count-count1,count1/2);  
            }
        }
    }
    template <typename T>
    auto Tree<T>::balance(pre_iterator<T>& it,pre_iterator<T>& it1,pre_iterator<T>& end) -> Tree<T>&{
        vector<int> elements;
        for(;it!=end;++it){
          elements.push_back(*it);  
        }
        --it;
        for(;it!=it1;--it){
        }
        delete_tree();
        int count=elements.size()/2;
        push_back(root,root,elements[count]);
        balance(elements,count,(count/2)+1);
        for(int i=elements.size()/2;i>=0;i--)
            push_back(root,root,elements[i]);
        for(int i=elements.size()/2;i<elements.size();i++)
            push_back(root,root,elements[i]);
    }
    template <typename T>
    auto Tree<T>::show() -> void{
        show(root,1);
    }
    template <typename T>
    auto Tree<T>::show(Node<T>* root, T stage) const -> void {
	if (root->right != nullptr)
		show(root->right,stage + 1);
	if (root != this->root && root->data != nullptr) {
		cout.width(stage * 4);
		cout << "--";
	}
	if(root->data!=nullptr)
	    cout << "(" << *(root->data)<< ")" << endl;
	if (root->left != nullptr)
		show(root->left,stage + 1);
}

    template <typename T>
    auto Tree<T>::push_back(Node<T>*& root, Node<T>*& parent,const T& value) -> Node<T>* {
    if (root == nullptr) {
        root = new Node<T> {new int{value}, nullptr, nullptr, nullptr,false};
        if(root != this->root)
            root->parent = parent;
    } else {
        if (*(root->data) > value) {
            root->left = push_back(root->left, root, value);
        } else if (*(root -> data) < value) {
            root->right = push_back(root->right, root, value);
        } else if(*(root -> data) == value) {
            return root;
        }
    }
    return root;
}
    template <typename T>
    auto Tree<T>::begin() -> pre_iterator<T>{
        Node<T>* curr=root;
        while(curr->left!=nullptr){
            curr=curr->left;
        }
        curr->test=true;
        curr->left=new Node<T>;
        curr->left->left=nullptr;
        curr->left->right=nullptr;
        curr->left->parent=curr;
        curr->left->test=true;
        pre_iterator<T> iter(curr);
        return iter;
    }
    template <typename T>
    auto Tree<T>::end() -> pre_iterator<T>{
        Node<T>* curr=root;
        while(curr->right!=nullptr){
            curr=curr->right;
        }
        curr->right=new Node<T>;
        curr->right->left=nullptr;
        curr->right->right=nullptr;
        curr->right->parent=curr;
        pre_iterator<T> iter(curr->right);
        return iter;
    }
    
    template <typename T>
    auto Tree<T>::rbegin() -> post_iterator<T>{
        Node<T>* curr=root;
        while(curr->right!=nullptr){
            curr=curr->right;
        }
        curr->test=true;
        curr->right=new Node<T>;
        curr->right->left=nullptr;
        curr->right->right=nullptr;
        curr->right->parent=curr;
        curr->right->test=true;
        post_iterator<T> iter(curr);
        return iter;
    }
    
    template <typename T>
    auto Tree<T>::rend() -> post_iterator<T>{
        Node<T>* curr=root;
        while(curr->left!=nullptr){
            curr=curr->left;
        }
        curr->left=new Node<T>;
        curr->left->left=nullptr;
        curr->left->right=nullptr;
        curr->left->parent=curr;
        post_iterator<T> iter(curr->left);
        return iter;
    }
}
