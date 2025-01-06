std::vector<int> minOperations(std::string boxes) {
    int n = boxes.size();
    std::vector<int> answer(n, 0);

    // Left to right pass
    int balls = 0; // Number of balls to the left
    int moves = 0; // Accumulated moves from the left
    for (int i = 0; i < n; ++i) {
        answer[i] += moves;
        balls += (boxes[i] == '1'); // Update the count of balls
        moves += balls; // Update the moves
    }

    // Right to left pass
    balls = 0; // Number of balls to the right
    moves = 0; // Accumulated moves from the right
    for (int i = n - 1; i >= 0; --i) {
        answer[i] += moves;
        balls += (boxes[i] == '1'); // Update the count of balls
        moves += balls; // Update the moves
    }

    return answer;
}


/*
- Problem: For each box in the string `boxes`, calculate the minimum number of moves
           required to bring all the balls ('1's) to that box.

- Approach:
  1. Use two passes to efficiently calculate the moves:
     - **Left-to-right pass**:
       - Keep track of the number of balls (`balls`) encountered so far.
       - Accumulate the total moves (`moves`) required to bring these balls to the current box.
       - Update `answer[i]` with the cumulative moves for the current box.

     - **Right-to-left pass**:
       - Similarly, track the number of balls (`balls`) encountered so far from the right.
       - Accumulate the total moves (`moves`) required to bring these balls to the current box.
       - Add these moves to `answer[i]`.

  2. By combining results from both passes, `answer[i]` gives the total moves for each box.

- Complexity:
  - Time: O(n), where n is the length of the string `boxes`, since we make two linear passes.
  - Space: O(n) for the `answer` array.
*/
