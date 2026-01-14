/*
 * Problem 3454: Separate Squares II (POTD)
 * Language: C++
 */
struct SegmentTree {
    int n;                           
    vector<int> coverCount;          
    vector<double> coveredLen;       
    vector<double> xcoords;         
    SegmentTree(const vector<long long>& coords) {
        n = (int)coords.size() - 1; 
        xcoords.resize(coords.size());
        for(int i=0; i<(int)coords.size(); i++){
            xcoords[i] = (double)coords[i];
        }
        coverCount.resize(4*n, 0);
        coveredLen.resize(4*n, 0.0);
    }

    void clear() {
        fill(coverCount.begin(), coverCount.end(), 0);
        fill(coveredLen.begin(), coveredLen.end(), 0.0);
    }

    void updateRange(int idx, int left, int right, int ql, int qr, int val) {
        if(ql > right || qr < left) return;
    
        if(ql <= left && right <= qr) coverCount[idx] += val;
        else {
            int mid = (left + right) >> 1;
            updateRange(idx<<1, left, mid, ql, qr, val);
            updateRange((idx<<1) + 1, mid+1, right, ql, qr, val);
        }
        if(coverCount[idx] > 0) coveredLen[idx] = xcoords[right+1] - xcoords[left];
        else {
            if(left == right) coveredLen[idx] = 0.0;
            else coveredLen[idx] = coveredLen[idx<<1] + coveredLen[(idx<<1)+1];
        }
    }

    void update(long long xl, long long xr, int val) {
        if(xl >= xr) return; 
        int l = int(std::lower_bound(xcoords.begin(), xcoords.end(), (double)xl) - xcoords.begin());
        int r = int(std::lower_bound(xcoords.begin(), xcoords.end(), (double)xr) - xcoords.begin());
        if(l < r) updateRange(1, 0, n-1, l, r-1, val);
    }

    double getCoveredLength() const {
        return coveredLen[1];
    }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        struct Event {
            long long y;
            long long x1, x2;
            int type; 
        };
        
        vector<Event> events;
        events.reserve(2 * squares.size());
        vector<long long> xvals;
        xvals.reserve(2 * squares.size());
        
        for (auto &sq : squares) {
            long long x = sq[0], y = sq[1], l = sq[2];
            long long x2 = x + l, y2 = y + l;
            events.push_back({y, x, x2, +1});
            events.push_back({y2, x, x2, -1});
            xvals.push_back(x);
            xvals.push_back(x2);
        }
        
        sort(xvals.begin(), xvals.end());
        xvals.erase(unique(xvals.begin(), xvals.end()), xvals.end());
        
        sort(events.begin(), events.end(), [](auto &a, auto &b){
            if (a.y != b.y) return a.y < b.y;
            return a.type < b.type;
        });
        SegmentTree st(xvals);
        
        double totalArea = 0.0;
        if (!events.empty()) {
            st.update(events[0].x1, events[0].x2, events[0].type);
            double coverage = st.getCoveredLength();
            double prevY = (double)events[0].y;
            
            for (int i = 1; i < (int)events.size(); i++) {
                double curY = (double)events[i].y;
                double deltaY = curY - prevY;
                totalArea += coverage * deltaY;
                
                st.update(events[i].x1, events[i].x2, events[i].type);
                coverage = st.getCoveredLength();
                prevY = curY;
            }
        }
        
        if (fabs(totalArea) < 1e-15) {
            long long minY = LLONG_MAX;
            for (auto &sq : squares) {
                minY = min(minY, (long long)sq[1]);
            }
            return (double)minY; 
        }
        
        double halfArea = totalArea / 2.0;
        st.clear();  
        double partialArea = 0.0;
        double resultY = 0.0;
        
        if(!events.empty()) {
            st.update(events[0].x1, events[0].x2, events[0].type);
            double coverage = st.getCoveredLength();
            double prevY = (double)events[0].y;
            
            for (int i = 1; i < (int)events.size(); i++) {
                double curY = (double)events[i].y;
                double deltaY = curY - prevY;
                double segmentArea = coverage * deltaY;
                if (partialArea + segmentArea >= halfArea - 1e-15) {
                    if (fabs(coverage) < 1e-15) {
                        if (fabs(partialArea - halfArea) < 1e-9) {
                            return prevY; 
                        }
                    } else {
                        double needed = halfArea - partialArea; 
                        double yOffset = needed / coverage; 
                        return prevY + yOffset;
                    }
                }
                
                partialArea += segmentArea;
                
                st.update(events[i].x1, events[i].x2, events[i].type);
                coverage = st.getCoveredLength();
                prevY = curY;
            }
            return prevY;
        }
        
        return 0.0;
    }
};