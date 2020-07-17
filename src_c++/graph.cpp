ll INF = 1145141919810364;
template <typename T>
class edge
{
public:
    T cost, to, from;
    edge(T from, T to, T cost) : from(from), to(to), cost(cost) {}
};
template <typename T>
class Graph
{
public:
    vector<vector<edge<T>>> graph;

    Graph(T n, vector<T> from, vector<T> to, bool no_direction, vector<T> cost)
    {
        graph.resize(n);
        for (int i = 0; i < from.size(); i++)
        {
            edge<T> params(from[i], to[i], cost[i]);
            graph[from[i]].emplace_back(params);
            if (no_direction)
            {
                swap(params.from, params.to);
                graph[to[i]].emplace_back(params);
            }
        }
    }
    vector<ll> shortest_path;
    void Dijkstra(ll start)
    {
        shortest_path.resize(graph.size(), INF);
        shortest_path[start] = 0;
        priority_queue<P, vector<P>, greater<P>> que;
        que.emplace(0, start);
        while (!que.empty())
        {
            P p = que.top();
            que.pop();
            ll v = p.second;
            if (shortest_path[v] < p.first)
                continue;
            for (int i = 0; i < graph[v].size(); i++)
            {
                ll k = graph[v][i].to;
                ll l = graph[v][i].cost;
                if (shortest_path[k] > shortest_path[v] + l)
                {
                    shortest_path[k] = shortest_path[v] + l;
                    que.push(P(shortest_path[k], k));
                }
            }
        }
    }
    vector<vector<T>> Shortest_path;
    void Warshall_Froyd()
    {
        Shortest_path.resize(graph.size(), vector<T>(graph.size(), INF));
        for (int i = 0; i < graph.size(); i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                ll To = graph[i][j].to;
                ll Cost = graph[i][j].cost;
                Shortest_path[i][To] = Cost;
            }
        }
        for (int k = 0; k < graph.size(); k++)
        {
            for (int i = 0; i < graph.size(); i++)
            {
                for (int j = 0; j < graph.size(); j++)
                {
                    Shortest_path[i][j] = min(Shortest_path[k][j] + Shortest_path[i][k], Shortest_path[i][j]);
                }
            }
        }
    }
    vector<T> dpath(T t)
    {
        vector<T> path;
        for (; t != INF; t = shortest_path[t])
            path.emplace_back(t);
        reverse(path.begin(), path.end());
        return path;
    }
};
