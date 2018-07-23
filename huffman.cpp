
#include <bits/stdc++.h>

using namespace std;
string word;
int num;
char ltr[26];
string fqncy[26];
int increment = 0;
struct MinNode {

	
	char variable;


	unsigned freq;

	
	MinNode *lvertex, *rvertex;

	MinNode(char variable, unsigned freq)

	{

		lvertex = rvertex = NULL;
		this->variable = variable;
		this->freq = freq;
	}
};


struct compareVertex {

	bool operator()(MinNode* left, MinNode* right)

	{
		return (left->freq > right->freq);
	}
};

void display(){
    string huffman="";
    for(int i=0; i < word.length(); i++){
        for(int j=0;j<num;j++){
            if(word[i]==ltr[j]){
                huffman = huffman + fqncy[j];
                break;
                }
            }
        }
        cout<<"\nHuffman code: "+huffman;
      
    }
void displayCodes(struct MinNode* rootvertex, string str)
{

	if (!rootvertex){
    
		return;
	}
		

	if (rootvertex->variable != '$'){
	   
		cout << rootvertex->variable << ": " << str << "\t";
		 ltr[increment] = rootvertex->variable;
	    fqncy[increment] = str;
	    ++increment;
	}


	displayCodes(rootvertex->rvertex, str + "0");
	displayCodes(rootvertex->lvertex, str + "1");
	
}


void beginEncode(char variable[], int freq[], int length)
{
	struct MinNode *lvertex, *rvertex, *top;

	
	priority_queue<MinNode*, vector<MinNode*>, compareVertex> minHeap;

	for (int i = 0; i < length; ++i)
		minHeap.push(new MinNode(variable[i], freq[i]));

	
	while (minHeap.size() != 1) {

	
		
       
		rvertex = minHeap.top();
		minHeap.pop();
		
         lvertex = minHeap.top();
		minHeap.pop();
	
		top = new MinNode('$', rvertex->freq + lvertex->freq);

		top->lvertex = lvertex;
		top->rvertex = rvertex;

		minHeap.push(top);
	}

	
	displayCodes(minHeap.top(), "");
}


int main()
{
    
    cout<<"enter a word to convert into huffman code: ";
    cin>>word;
    cout<<"\n";
    string stg="";
  stg = stg + word[0];
  for(int i = 1; i < word.length(); i++){
      int calc = 0;
      for(int j = 0; j < stg.length(); j++){
          if(word[i]==stg[j])
          calc = calc + 1;
          }
          if(calc==0){
              stg = stg + word[i];
              }
      }

    num = stg.length();
  
	char a[num + 1];
	strcpy(a, stg.c_str());
	
   
	int weight[num + 1];
	  for(int k = 0; k < num; k++){
      weight[k]=count(word.begin(), word.end(), stg[k]);
      }



	
    	beginEncode(a, weight, num);
    	display();


	return 0;
}



