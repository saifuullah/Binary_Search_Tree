#include <iostream>
#include <stdlib.h>

using namespace std;
#define adder 10; ///for spaces to print tree in 2D

/***  First Class
****   Node Class
****
***/
class Node
{
private:
    Node *right;
    Node *left;
    int data;
public:
    Node(int d)
    {   right=NULL;
        left=NULL;
        data=d;
    }//END

    int getData()
    {   return data;
    }//END

    Node* getLeft()
    {   return left;
    }//END

    Node* getRight()
    {   return right;
    }//END

    void setLeft(Node *l)
    {   left=l;
    }//END

    void setRight(Node *r)
    {   right=r;
    }
    void setData(int d)
    {
        data=d;
    }



}; ///END OF NODE CLASS





class bst_CLASS
{
private:
    Node *root;

public:

    bst_CLASS()         ///CONSTRUCTER
    {   root=NULL;
    } //END


    void add_DATA_TO_BST(int d)        ///THIS WILL ADD DATA TO BST
    {   Node *temp_new=new Node(d);    ///USING WHILE LOOP
        Node *temp = root;             ///COMPLEXITY IS BIG-O(H)
        if(root==NULL)
        {   root=temp_new;
            return;
        }
        else
        {   while(1)
            {   if(d<temp->getData())
                {   if(temp->getLeft()==NULL)
                    {   temp->setLeft(temp_new);
                        return;
                    }
                    else
                        temp=temp->getLeft();
                } // check for less
                else if(d>temp->getData())
                {   if(temp->getRight()==NULL)
                    {   temp->setRight(temp_new);
                        return;
                    }
                    else
                        temp=temp->getRight();
                }//check for greater
            }//while loop end
        }//else end
    }//ENd of function


    void add_with_r(int d)                ///*****THESE TWO FUNCTIONS WILL ADD DATA TO BST
    {                                     ///*****USING RECURSION
        Node *temp2=new Node(d);          ///*****COMPLEXITY IS BIG-O(H)
        Node *temp=root;                  ///*****SOMETIMES MAY BE SMALLER DEPENDING ON STRUCTURE
        if(temp==NULL)                    ///*****BINARY TREEE
            root=temp2;
        else
        addd(d,temp,temp2);
    }//End of function

    void addd(int d, Node *temp, Node *temp2)
    {
        if(temp->getLeft()==NULL && d<temp->getData())
            {
            temp->setLeft(temp2);
            return;
            }
        else if(temp->getRight()==NULL && d>temp->getData())
            {
            temp->setRight(temp2);
            return;
            }
        else if(d<temp->getData())
            addd(d,temp->getLeft(), temp2);

        else addd(d,temp->getRight(),temp2);


    }//End of function

    void display(int n)                    ///****THIS IS DISPLAY FUNCTION U
    {   Node *temp=root;              ///****USING RECUSRIONS
        if(temp==NULL)                ///****BIG-(N)
        {   cout<<"Empty "<<endl;
            return;
        }
        else{
            if(n==1)
            display_IN(temp);
            else if(n==2)
            display_POST(temp);
        else if(n==3)
            display_PRE(temp);
            }
    }//END of function


    void display_IN(Node *temp)
    {
    /**
        cout <<temp->getData()<<endl;
        if(temp->getLeft()!=NULL)
            display_2(temp->getLeft());
        if(temp->getRight()!=NULL)
            display_2(temp->getRight());
            */
          if(temp==NULL)
            return;
        else
        {

            display_IN(temp->getLeft());
            cout<<temp->getData()<<endl;
            display_IN(temp->getRight());

        }
    }//END of Function



    void display_PRE(Node *temp)
    {
    /**
        cout <<temp->getData()<<endl;
        if(temp->getLeft()!=NULL)
            display_2(temp->getLeft());
        if(temp->getRight()!=NULL)
            display_2(temp->getRight());
            */
          if(temp==NULL)
            return;
        else
        {
            cout<<temp->getData()<<endl;
            display_PRE(temp->getLeft());
            display_PRE(temp->getRight());
        }
    }//END of Function






           void display_POST(Node *temp)
    {
    /**
        cout <<temp->getData()<<endl;
        if(temp->getLeft()!=NULL)
            display_2(temp->getLeft());
        if(temp->getRight()!=NULL)
            display_2(temp->getRight());
            */
          if(temp==NULL)
            return;
        else
        {
            display_POST(temp->getLeft());
            display_POST(temp->getRight());
            cout<<temp->getData()<<endl;

        }
    }//END of Function
                                            ///***This is 2D Function
void print_final(Node *temp, int space)     ///***PRINT TREE IN 2D
{
    if (temp == NULL)
        return;
    space += adder;

   print_final(temp->getRight(), space);
    cout<<endl;
    int x=adder;
    for (int i = x; i < space; i++)
        cout<<" ";
    cout<<temp->getData()<<"\n";
    print_final(temp->getLeft(), space);
}//End of function

void print_in_2D()   ///This wrapper of above function
{
    Node *temp=root;
    print_final(temp, 0);
}//End of function


 /***********       BELOW IS SEARCH FUNCTION THAT WORKS ON RECURSION
 ************      MAX TIME COMPLEXITY IS EQUAL TO HIEGHT OF TREE
 ************      SOME TIMES SMALLER THAN HIEGHT ****/

int searchData(Node *temp,int d)
{
    if(temp==NULL)
        return -1;
    if(d<temp->getData())
        searchData(temp->getLeft(),d);

    else if(temp->getData() < d)
        searchData(temp->getRight(),d);

        else return 0;
}//end of function

int searchDATA(int d)
{
    Node *temp=root;
    if(temp==NULL)
        return -1;
    else
    {
        return searchData(temp,d);
    }
}//End of function

int search_loops(int d)    ///******This Function will perform search on the basis of loops
{
    Node *temp=root;
    if(temp==NULL)
      return -1;

      else
      {
          while(1)
          {
              if(temp==NULL)
                return -1;     //  -1 means false
           if(d<temp->getData())
             temp=temp->getLeft();
           else if(d>temp->getData())
            temp=temp->getRight();
           else if(temp->getData()==d)
            return 0;          // 0 means true
          }//loop
      }//else
}//End of function

void removeData(int d)
{
    Node *temp=root;
    Node *prev;
    if(searchDATA(d)==0)
    {

    if(root->getData()==d && root->getLeft()==NULL && root->getRight()==NULL)
        root=NULL;
    else
    {
     while(temp->getData()!=d)
     {
         if(d<temp->getData())
         {   prev=temp;
            temp=temp->getLeft();
         }
         else
          {
            prev=temp;
            temp=temp->getRight();
          }
     }
     if(temp->getLeft()==NULL && temp->getRight()==NULL)
     {
         cout<<prev->getData() <<"     "<<temp->getData()<<endl;
         if(prev->getLeft()!=NULL && prev->getLeft()->getData()==d)
            prev->setLeft(NULL);
         else
            prev->setRight(NULL);
     }
     else
         r_root(temp,d);
    }
    }
    else
        cout <<"Sorry Data is Not found "<<endl;
}//End oF function

void r_root(Node *temp, int d)
{
    Node *prev,*temp2;
    if(temp->getLeft()==NULL && temp->getRight()!=NULL)
        {
            if(temp->getRight()->getLeft()==NULL && temp->getRight()->getRight()!=NULL)
                {
                    temp->setData(temp->getRight()->getData());
                    temp->setRight(temp->getRight()->getRight());
                }
            else if(temp->getRight()->getLeft()==NULL && temp->getRight()->getRight()==NULL)
            {
                temp->setData(temp->getRight()->getData());
                temp->setRight(NULL);
            }
                else
            {
                    temp2=temp;
                    prev=temp;
                    temp=temp->getRight();
         while(1)
            {
                if(temp->getLeft()==NULL)
                    break;
                prev=temp;
                temp=temp->getLeft();
            }
            temp2->setData(temp->getData());
            if(temp->getRight()==NULL)
            prev->setLeft(NULL);
            else
                prev->setLeft(temp->getRight());
            }
        }
    else if(temp->getLeft()!=NULL)
    {
        if(temp->getLeft()->getRight()==NULL && temp->getLeft()->getLeft()==NULL)
          {
              temp->setData(temp->getLeft()->getData());
              temp->setLeft(NULL);
          }
          else if(temp->getLeft()->getRight()==NULL && temp->getLeft()->getLeft()!=NULL)
          {
              temp->setData(temp->getLeft()->getData());
              temp->setLeft(temp->getLeft()->getLeft());

          }
          else
          {
              temp2=temp;
              prev=temp;
              temp=temp->getLeft();
             while(1)
             {
                 if(temp->getRight()==NULL)
                    break;
                 prev=temp;
                 temp=temp->getRight();
             }
             temp2->setData(temp->getData());
             if(temp->getLeft()==NULL)
             prev->setRight(NULL);
             else
                prev->setRight(temp->getLeft());
          }

    }
}//End of function







};///END OF bst_CLASS

int main()
{   bst_CLASS myb;
    int choice,dat,x=0,result,n;
    do
    {   //system("CLS");
        cout <<"Enter 1 To add Data "<<endl;
        cout <<"Enter 2 To Display  "<<endl;
        cout <<"Enter 3 To Display in 2D "<<endl;
        cout <<"Enter 4 To Search For data "<<endl;
        cout <<"Enter 5 To Remove Data  "<<endl;
        cin>>choice;
        switch(choice)
        {   case 1:
                cout<<"Enter data you want add "<<endl;
                cin>>dat;
                result = myb.searchDATA(dat);
                if(result==0)
                    cout <<"Cannot add because this data is always present !!!! "<<endl;
                else
                myb.add_DATA_TO_BST(dat);
                //myb.add_with_r(dat);
                break;
            case 2:
                cout<<"Which Display you want "<<endl;
                cout<<"1 ->IN-Order"<<endl<<"2 ->Post-Order "<<endl<<"3 -> Pre-Order "<<endl;
                cin>>n;
                myb.display(n);
                break;
            case 3:
                myb.print_in_2D();
                break;
            case 4:
                cout<<"Enter the data you want to search for :";
                cin>>dat;
                result = myb.search_loops(dat);
                if(result==-1)
                    cout<<"Data is not Found "<<endl;
                else
                    cout<<"Data is Present "<<endl;
                break;
            case 5:
                cout<<"Enter data you want to remove "<<endl;
                cin>>dat;
                myb.removeData(dat);
                break;
            default:
                cout<<endl<<"Invalid Choice "<<endl<<endl;
                break;
        }
        cout <<"Enter -1 to exit    :";
        cin>>x;
    }
    while(x!=-1);
    return 0;
}
