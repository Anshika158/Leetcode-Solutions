class StockSpanner {
public:
    vector<int> prices;
    vector<int> spans;

    StockSpanner() {
        // No need to explicitly re-declare vectors here.
    }

    int next(int price) {
        int span = 1 ; // the current day start from 1

        while(!prices.empty() && prices.back()<=price){
            span+=spans.back();

            //remove the span of the last price to the current price
            prices.pop_back();
            spans.pop_back();
        }
        prices.push_back(price);
        spans.push_back(span);

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
