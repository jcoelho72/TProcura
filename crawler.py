import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin, urlparse
from collections import deque

BASE_URL = "https://jcoelho72.github.io/TProcura/"
visited = set()
queue = deque([BASE_URL])
output_file = "tprocura_corpus.txt"

def is_same_domain(url):
    return urlparse(url).netloc == urlparse(BASE_URL).netloc

with open(output_file, "w", encoding="utf-8") as f:
    while queue:
        url = queue.popleft()
        if url in visited:
            continue
        visited.add(url)

        try:
            r = requests.get(url)
            r.raise_for_status()
        except:
            continue

        soup = BeautifulSoup(r.text, "html.parser")

        for script in soup(["script", "style", "noscript"]):
            script.extract()

        text = soup.get_text(separator="\n", strip=True)

        f.write(f"\n\n=== URL: {url} ===\n")
        f.write(text)
        f.write("\n")

        for link in soup.find_all("a", href=True):
            new_url = urljoin(url, link["href"])
            if is_same_domain(new_url) and new_url not in visited:
                queue.append(new_url)
