@page tutorial_adversas5a Procuras Adversas - Introdução

\htmlonly

<div style="padding:12px; border:1px solid #444; border-radius:6px; background:#222; margin:20px 0; color:#ddd;">
  <div style="font-size:12px; opacity:0.8; margin-bottom:6px;">
    <a href="tutorial_adversas.html" style="color:#9cf; text-decoration:none;">Tutorial: Procuras Adversas</a>
  </div>
  <div style="display:flex; flex-wrap:wrap; gap:12px; justify-content:center;">
    <a href="tutorial_adversaslit.html" style="color:#9cf;">📖 Literatura</a>
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">👓 Introdução</span>
    <a href="tutorial_adversas5b.html" style="color:#9cf;">👓 MiniMax</a>
    <a href="tutorial_adversas5c.html" style="color:#9cf;">👓 Monte Carlo</a>
    <a href="tutorial_galominimax.html" style="color:#9cf;">✏️ Galo MiniMax</a>
    <a href="tutorial_galoalfabeta.html" style="color:#9cf;">✏️ Galo alfa/beta</a>
    <a href="teste_jogo_do_galo.html" style="color:#9cf;">💻 Jogo do Galo</a>
    <a href="teste_jogo_em_linha.html" style="color:#9cf;">💻 Jogo em Linha</a>
  </div>
</div>

<div style="display:flex; gap:20px;">
<iframe src="https://player.vimeo.com/video/803548145" width="300" height="169" frameborder="0" allow="fullscreen"></iframe>
</div>

\endhtmlonly

[📄 Ver slides (PDF)](PVP5A.pdf)


\htmlonly

<div id="todas-perguntas" style="display:none;">

  <details class="pergunta">
    <summary><strong>⚡ Ação: </strong> Pergunta 1...</summary>
    Resposta 1...
    <a href="" style="color:#9cf; font-weight:bold; margin-left:10px;">🎲</a>
  </details>

  <details class="pergunta">
    <summary><strong>⚡ Ação: </strong> Pergunta 2...</summary>
    Resposta 2...
    <a href="" style="color:#9cf; font-weight:bold; margin-left:10px;">🎲</a>
  </details>

  <details class="pergunta">
    <summary><strong>⚡ Ação: </strong> Pergunta 3...</summary>
    Resposta 3...
    <a href="" style="color:#9cf; font-weight:bold; margin-left:10px;">🎲</a>
  </details>

  <details class="pergunta">
    <summary><strong>⚡ Ação: </strong> Pergunta 4...</summary>
    Resposta 4...
    <a href="" style="color:#9cf; font-weight:bold; margin-left:10px;">🎲</a>
  </details>

  <details class="pergunta">
    <summary><strong>⚡ Ação: </strong> Pergunta 5...</summary>
    Resposta 5...
    <a href="" style="color:#9cf; font-weight:bold; margin-left:10px;">🎲</a>
  </details>

</div>

<div id="perguntas-escolhidas"></div>



<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="tutorial_adversaslit.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="tutorial_adversas5b.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     Próximo passo ▶ </a>
</div>

<script>
document.addEventListener("DOMContentLoaded", function() {
  const todas = Array.from(document.querySelectorAll("#todas-perguntas .pergunta"));
  const idx = Math.floor(Math.random() * todas.length);
  const destino = document.getElementById("perguntas-escolhidas");
  destino.appendChild(todas[idx]);
});
</script>



\endhtmlonly

