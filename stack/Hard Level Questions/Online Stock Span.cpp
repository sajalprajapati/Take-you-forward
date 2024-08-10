/*
If it is given the vcector then we can apply previous greater element using the stack approach by storing the indexes in the stack.
*/
class StockSpanner {
public:
    stack<pair<int,int>> stk;
    StockSpanner() {
        
    }
    
    int next(int price) 
    {
      int span=1;
      while(!stk.empty() and stk.top().first<=price)
      {
        span=span+stk.top().second;
        stk.pop();
      }  

      stk.push({price,span});

      return span;
    }
};

