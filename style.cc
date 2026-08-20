@import url('https://fonts.googleapis.com/css2?family=Cormorant+Garamond:wght@500;600;700&family=Poppins:wght@400;500;600;700&display=swap');

:root {
  --bg: #f4ead9;
  --paper: #fffaf0;
  --paper-dark: #eadbc3;

  --brown: #4a342d;
  --brown-light: #876e60;

  --red: #a94b4b;
  --red-light: #d98d86;

  --blue: #536d8c;
  --blue-light: #8fa9c4;

  --gold: #b88a4a;

  --shadow: 0 25px 70px rgba(74, 52, 45, .15);
}

* {
  margin: 0;
  padding: 0;
  box-sizing: border-box;
}

html {
  scroll-behavior: smooth;
}

body {
  min-height: 100vh;

  display: flex;
  justify-content: center;
  align-items: center;

  padding: 35px 15px;

  font-family: "Poppins", sans-serif;

  color: var(--brown);

  background:
    radial-gradient(
      circle at 15% 15%,
      rgba(184, 138, 74, .15),
      transparent 25%
    ),
    radial-gradient(
      circle at 85% 85%,
      rgba(169, 75, 75, .12),
      transparent 25%
    ),
    var(--bg);

  overflow-x: hidden;
}

body::before {
  content: "✦   ❀   ✦   ❀   ✦   ❀   ✦";

  position: fixed;
  top: 15px;
  left: 0;

  width: 100%;

  text-align: center;

  font-size: 18px;
  letter-spacing: 10px;

  color: rgba(74, 52, 45, .08);

  pointer-events: none;
}

.game-container {
  width: min(100%, 760px);
}

.game-header {
  text-align: center;
  margin-bottom: 25px;
}

.eyebrow {
  font-size: 9px;
  font-weight: 700;

  letter-spacing: 4px;

  color: var(--brown-light);

  margin-bottom: 7px;
}

.game-header h1 {
  font-family: "Cormorant Garamond", serif;

  font-size: clamp(60px, 11vw, 90px);

  line-height: .8;

  font-weight: 700;

  letter-spacing: -2px;
}

.game-header h1 span {
  color: var(--red);
}

.description {
  margin-top: 18px;

  font-size: 12px;

  color: var(--brown-light);
}

.game-panel {
  position: relative;

  padding: 30px;

  border: 1px solid rgba(255,255,255,.7);

  border-radius: 32px;

  background: rgba(255,250,240,.72);

  box-shadow: var(--shadow);

  backdrop-filter: blur(15px);
}

.game-panel::before {
  content: "꧁";

  position: absolute;

  top: 10px;
  left: 15px;

  font-size: 35px;

  color: var(--gold);

  opacity: .25;
}

.game-panel::after {
  content: "꧂";

  position: absolute;

  bottom: 10px;
  right: 15px;

  font-size: 35px;

  color: var(--gold);

  opacity: .25;
}

.top-info {
  display: grid;

  grid-template-columns: 1fr auto 1fr;

  align-items: center;

  gap: 15px;

  max-width: 600px;

  margin: auto;
}

.player {
  display: flex;

  align-items: center;

  gap: 12px;

  padding: 12px 15px;

  border: 1px solid transparent;

  border-radius: 18px;

  background: rgba(255,255,255,.45);

  transition: .3s ease;
}

.player.active {
  background: rgba(255,255,255,.8);

  border-color: var(--paper-dark);

  transform: translateY(-2px);

  box-shadow: 0 8px 20px rgba(74,52,45,.08);
}

.player-piece {
  width: 38px;
  height: 38px;

  flex-shrink: 0;

  border-radius: 50%;

  box-shadow:
    inset -5px -6px 8px rgba(0,0,0,.15),
    inset 4px 4px 7px rgba(255,255,255,.35),
    0 5px 10px rgba(0,0,0,.12);
}

.red-piece {
  background: radial-gradient(
    circle at 35% 30%,
    #edaaa1,
    var(--red)
  );
}

.blue-piece {
  background: radial-gradient(
    circle at 35% 30%,
    #b8cce0,
    var(--blue)
  );
}

.player small,
.score-card small {
  display: block;

  font-size: 8px;

  letter-spacing: 2px;

  color: var(--brown-light);
}

.player strong {
  display: block;

  font-family: "Cormorant Garamond", serif;

  font-size: 22px;

  line-height: 1;
}

.turn-box {
  text-align: center;

  min-width: 100px;
}

.turn-box small {
  display: block;

  font-size: 8px;

  letter-spacing: 2px;

  color: var(--brown-light);
}

.turn-box strong {
  display: block;

  margin-top: 2px;

  font-family: "Cormorant Garamond", serif;

  font-size: 20px;
}

.status {
  max-width: 470px;

  margin: 20px auto;

  padding: 11px 18px;

  border-radius: 50px;

  text-align: center;

  font-size: 11px;

  color: var(--brown-light);

  background: rgba(255,255,255,.5);

  border: 1px solid rgba(74,52,45,.06);
}

.board-area {
  display: flex;
  justify-content: center;

  margin: 10px 0 30px;
}

.board {
  position: relative;

  width: min(75vw, 390px);
  aspect-ratio: 1;

  border-radius: 22px;

  background:
    radial-gradient(
      circle at 50% 50%,
      #f4e8d1 0%,
      #e8d5b8 100%
    );

  box-shadow:
    inset 0 0 0 8px rgba(255,255,255,.2),
    0 18px 35px rgba(74,52,45,.15);
}

.board::before {
  content: "";

  position: absolute;

  inset: 13px;

  border: 1px solid rgba(74,52,45,.16);

  border-radius: 12px;

  pointer-events: none;
}

.line {
  position: absolute;

  background: rgba(74,52,45,.5);

  transform-origin: center;

  pointer-events: none;
}

.horizontal {
  left: 13%;
  width: 74%;
  height: 2px;
}

.vertical {
  top: 13%;
  width: 2px;
  height: 74%;
}

.line-h1 {
  top: 13%;
}

.line-h2 {
  top: 50%;

  transform: translateY(-50%);
}

.line-v1 {
  left: 13%;
}

.line-v2 {
  left: 50%;

  transform: translateX(-50%);
}

.line-d1 {
  width: 104%;
  height: 2px;

  top: 50%;
  left: -2%;

  transform: rotate(45deg);
}

.line-d2 {
  width: 104%;
  height: 2px;

  top: 50%;
  left: -2%;

  transform: rotate(-45deg);
}

.line-d3 {
  display: none;
}

.line-d4 {
  display: none;
}

.point {
  position: absolute;

  width: 15%;
  height: 15%;

  transform: translate(-50%, -50%);

  border: 4px solid var(--paper);

  border-radius: 50%;

  background: var(--brown);

  box-shadow:
    0 3px 7px rgba(0,0,0,.2);

  cursor: pointer;

  z-index: 5;

  transition:
    transform .2s ease,
    background .2s ease,
    box-shadow .2s ease;
}

.point:nth-of-type(9) {
  top: 13%;
  left: 13%;
}

.point:nth-of-type(10) {
  top: 13%;
  left: 50%;
}

.point:nth-of-type(11) {
  top: 13%;
  left: 87%;
}

.point:nth-of-type(12) {
  top: 50%;
  left: 13%;
}

.point:nth-of-type(13) {
  top: 50%;
  left: 50%;
}

.point:nth-of-type(14) {
  top: 50%;
  left: 87%;
}

.point:nth-of-type(15) {
  top: 87%;
  left: 13%;
}

.point:nth-of-type(16) {
  top: 87%;
  left: 50%;
}

.point:nth-of-type(17) {
  top: 87%;
  left: 87%;
}

.point:hover {
  transform: translate(-50%, -50%) scale(1.12);
}

.point.selectable {
  animation: pulse 1s infinite;
}

.point.selected {
  transform: translate(-50%, -50%) scale(1.15);

  box-shadow:
    0 0 0 5px rgba(184,138,74,.35),
    0 6px 12px rgba(0,0,0,.2);
}

.point.movable {
  background: var(--gold);

  box-shadow:
    0 0 0 5px rgba(184,138,74,.15);
}

.piece {
  position: absolute;

  width: 68%;
  height: 68%;

  left: 16%;
  top: 16%;

  border-radius: 50%;

  pointer-events: none;

  box-shadow:
    inset -6px -7px 10px rgba(0,0,0,.18),
    inset 5px 5px 8px rgba(255,255,255,.4),
    0 4px 8px rgba(0,0,0,.18);

  animation: pieceIn .25s ease;
}

.piece.red {
  background:
    radial-gradient(
      circle at 32% 25%,
      #efb0a7,
      var(--red) 65%,
      #783333
    );
}

.piece.blue {
  background:
    radial-gradient(
      circle at 32% 25%,
      #bfd3e5,
      var(--blue) 65%,
      #344b65
    );
}

.winning-piece {
  animation: winnerPiece .7s ease infinite alternate;
}

.score-board {
  display: grid;

  grid-template-columns: 1fr 1fr 1fr;

  max-width: 500px;

  margin: auto;

  border-top: 1px solid rgba(74,52,45,.1);
  border-bottom: 1px solid rgba(74,52,45,.1);
}

.score-card {
  position: relative;

  text-align: center;

  padding: 15px;

  border-right: 1px solid rgba(74,52,45,.1);
}

.score-card:last-child {
  border-right: none;
}

.score-card strong {
  display: block;

  margin-top: 1px;

  font-family: "Cormorant Garamond", serif;

  font-size: 28px;
}

.score-dot {
  display: inline-block;

  width: 7px;
  height: 7px;

  margin-right: 4px;

  border-radius: 50%;
}

.score-dot.red {
  background: var(--red);
}

.score-dot.blue {
  background: var(--blue);
}

.controls {
  text-align: center;

  margin-top: 25px;
}

.reset-button {
  border: none;

  padding: 12px 27px;

  border-radius: 50px;

  background: var(--brown);

  color: white;

  font-family: inherit;

  font-size: 11px;

  cursor: pointer;

  transition: .3s ease;
}

.reset-button:hover {
  transform: translateY(-2px);

  background: var(--red);

  box-shadow: 0 8px 20px rgba(169,75,75,.2);
}

footer {
  padding-top: 20px;

  text-align: center;

  font-size: 9px;

  letter-spacing: 1px;

  color: var(--brown-light);
}

footer span {
  margin: 0 8px;

  color: var(--gold);
}

.winner-modal {
  position: fixed;

  inset: 0;

  display: none;
  place-items: center;

  padding: 20px;

  background: rgba(48,35,30,.45);

  backdrop-filter: blur(8px);

  z-index: 100;
}

.winner-modal.show {
  display: grid;

  animation: fadeIn .25s ease;
}

.modal-content {
  width: min(90%, 370px);

  padding: 40px 25px;

  text-align: center;

  border-radius: 28px;

  background: var(--paper);

  box-shadow:
    0 30px 80px rgba(0,0,0,.25);

  animation: popup .4s ease;
}

.flower {
  font-size: 42px;

  color: var(--gold);
}

.modal-content > p {
  margin-top: 5px;

  font-size: 9px;

  letter-spacing: 3px;

  color: var(--brown-light);
}

.modal-content h2 {
  margin: 5px 0 20px;

  font-family: "Cormorant Garamond", serif;

  font-size: 42px;

  color: var(--red);
}

#winnerPiece {
  width: 55px;
  height: 55px;

  margin: 0 auto 25px;

  border-radius: 50%;

  box-shadow:
    inset -7px -7px 10px rgba(0,0,0,.18),
    inset 5px 5px 8px rgba(255,255,255,.4),
    0 8px 15px rgba(0,0,0,.15);
}

#winnerPiece.red {
  background:
    radial-gradient(
      circle at 32% 25%,
      #efb0a7,
      var(--red) 65%,
      #783333
    );
}

#winnerPiece.blue {
  background:
    radial-gradient(
      circle at 32% 25%,
      #bfd3e5,
      var(--blue) 65%,
      #344b65
    );
}

#nextRound {
  border: none;

  padding: 12px 30px;

  border-radius: 50px;

  background: var(--brown);

  color: white;

  font-family: inherit;

  cursor: pointer;

  transition: .3s ease;
}

#nextRound:hover {
  background: var(--red);

  transform: translateY(-2px);
}

@keyframes pulse {
  0%, 100% {
    box-shadow:
      0 0 0 3px rgba(184,138,74,.1);
  }

  50% {
    box-shadow:
      0 0 0 8px rgba(184,138,74,.25);
  }
}

@keyframes pieceIn {
  from {
    transform: scale(.5);
    opacity: 0;
  }

  to {
    transform: scale(1);
    opacity: 1;
  }
}

@keyframes winnerPiece {
  from {
    transform: scale(1);
  }

  to {
    transform: scale(1.1);
  }
}

@keyframes fadeIn {
  from {
    opacity: 0;
  }

  to {
    opacity: 1;
  }
}

@keyframes popup {
  from {
    opacity: 0;
    transform: translateY(20px) scale(.9);
  }

  to {
    opacity: 1;
    transform: translateY(0) scale(1);
  }
}

@media (max-width: 600px) {

  body {
    padding: 25px 10px;
  }

  .game-panel {
    padding: 22px 14px;
    border-radius: 25px;
  }

  .top-info {
    gap: 6px;
  }

  .player {
    padding: 9px;
    gap: 7px;
  }

  .player-piece {
    width: 30px;
    height: 30px;
  }

  .player strong {
    font-size: 18px;
  }

  .player small {
    font-size: 7px;
  }

  .turn-box {
    min-width: 70px;
  }

  .turn-box strong {
    font-size: 17px;
  }

  .board {
    width: min(88vw, 360px);
  }

  .status {
    font-size: 10px;
  }
}
