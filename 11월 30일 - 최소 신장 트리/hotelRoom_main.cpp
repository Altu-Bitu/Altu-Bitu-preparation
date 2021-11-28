int main() {
    ll k = 10;
    vector<ll> room_number = {1, 3, 4, 1, 3, 1};
    vector<ll> result = solution(k, room_number);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';
}