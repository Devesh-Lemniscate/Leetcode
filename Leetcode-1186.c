/*
 * Problem 1186: Maximum Subarray Sum with One Deletion
 * Language: C
 */
            notTake = max(notTake+arr[i], arr[i]);
            ans = max(ans, max(take, notTake));
        }
        return ans;
    }
};