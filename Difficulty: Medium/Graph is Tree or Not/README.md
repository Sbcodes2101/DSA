<h2><a href="https://www.geeksforgeeks.org/problems/is-it-a-tree/1">Graph is Tree or Not</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">You are given an undirected graph of <strong>n</strong> nodes (numbered from 0 to n-1) and <strong>m</strong> edges. Return 1 if the graph is a tree, else return 0.</span></p>
<p><span style="font-size: 18px;"><strong>Note:</strong> The input graph can have self-loops and multiple edges.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong><span style="font-size: 18px;">Input:</span> </strong></span><span style="font-size: 18px;">n = 4, m = 3</span><span style="font-size: 18px;">, edges</span><span style="font-size: 18px;"> = [[0, 1], [1, 2], [1, 3]]</span>
<span style="font-size: 18px;"><strong>Output:</strong> 1</span>
<span style="font-size: 18px;"><strong>Explanation: </strong>Every node is reachable and the graph has no loops, so it is a tree</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong></span><span style="font-size: 18px;">n = 4, m = 3</span><span style="font-size: 18px;">, edges</span><span style="font-size: 18px;"> = [[0, 1], [1, 2], [2, 0]]</span>
<span style="font-size: 18px;"><strong>Output:</strong> 0</span>
<span style="font-size: 18px;"><strong>Explanation:</strong> 3 is not connected to any </span><span style="font-size: 18px;">node and there is a cycle 0-&gt;1-&gt;2-&gt;0, so</span> <span style="font-size: 18px;">it is not a tree.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= n &lt;= 2*10<sup>5</sup><br>0 &lt;= m &lt;= 2*10<sup>5</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>DFS</code>&nbsp;<code>Graph</code>&nbsp;<code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;