class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
      //very easy questions...
      vector<int> stk;

      for(auto &a:asteroids)
      {
        while (!stk.empty() && stk.back() > 0 && a < 0)
        {
            int sum=stk.back()+a;

            if(sum<0)
            {
             stk.pop_back();//positive wala destroy ho gya!!!!!!!!!!
            }

            else if(sum>0)
            {
             a=0;//negative wala destory ho gya...
            }
            else if(sum==0)
            {
              a=0;
              stk.pop_back();
            }
        }

        if(a!=0)
        {
            stk.push_back(a);
        }
      }

      return stk;  
    }
};