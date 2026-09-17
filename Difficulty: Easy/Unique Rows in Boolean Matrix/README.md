<h2><a href="https://www.geeksforgeeks.org/problems/unique-rows-in-boolean-matrix/1">Unique Rows in Boolean Matrix</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given a binary matrix your task is to find all unique rows of the given matrix in the order of their appearance in the matrix. </span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>mat[][] = [[1 1 0 1], <br>                [1 0 0 1],<br>                [1 1 0 1]]
<strong>Output: </strong>[[1 1 0 1],<br>        [1 0 0 1]]<strong>
Explanation:</strong>
The two unique rows are R<sub>1</sub>: [1 1 0 1] and R<sub>2</sub>: [1 0 0 1]. <br>As R<sub>1 </sub>first appeared at row-0 and R<sub>2</sub> appeared at row-1, in the resulting list, R<sub>1</sub> is kept before R<sub>2</sub>.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> mat[][] = [[0 0 0 1],</span><br><span style="font-size: 14pt;">                [0 0 0 1]]
<strong>Output: </strong>[0 0 0 1]<strong>
Explanation: </strong>
Only unique row is [0 0 0 1].</span></pre>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Zoho</code>&nbsp;<code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Set</code>&nbsp;<code>Matrix</code>&nbsp;<code>Trie</code>&nbsp;<code>Advanced Data Structure</code>&nbsp;