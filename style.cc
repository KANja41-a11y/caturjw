@import url('https://fonts.googleapis.com/css2?family=Cormorant+Garamond:wght@500;600;700&family=Poppins:wght@400;500;600;700&display=swap');


:root {

  --background: #f4eadb;

  --card: #fffaf2;

  --brown: #4b3830;

  --brown-light: #8b7568;

  --red: #a94f4f;

  --red-light: #d58b83;

  --blue: #526f91;

  --blue-light: #9bb1c9;

  --gold: #b58a4e;

  --line: #735c4f;

  --shadow:
    0 25px 70px rgba(75, 56, 48, .15);
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

  padding: 30px 15px;

  font-family: "Poppins", sans-serif;

  color: var(--brown);

  background:

    radial-gradient(
      circle at 10% 10%,
      rgba(181, 138, 78, .15),
      transparent 25%
    ),

    radial-gradient(
      circle at 90% 90%,
      rgba(169, 79, 79, .12),
      transparent 25%
    ),

    var(--background);

  overflow-x: hidden;
}


body::before {

  content: "✦  ❀  ✦  ❀  ✦  ❀  ✦";

  position: fixed;

  top: 20px;

  left: 0;

  width: 100%;

  text-align: center;

  color: rgba(75, 56, 48, .08);

  font-size: 18px;

  letter-spacing: 12px;

  pointer-events: none;
}


.container {

  width: min(100%, 760px);

  margin: auto;
}


/* =========================
   HEADER
========================= */


.header {

  text-align: center;

  margin-bottom: 30px;
}


.label {

  font-size: 9px;

  font-weight: 700;

  letter-spacing: 4px;

  color: var(--brown-light);

  margin-bottom: 8px;
}


.header h1 {

  font-family: "Cormorant Garamond", serif;

  font-size: clamp(60px, 12vw, 90px);

  line-height: .8;

  letter-spacing: -2px;
}


.header h1 span {

  color: var(--red);
}


.subtitle {

  margin-top: 18px;

  font-size: 12px;

  color: var(--brown-light);
}


/* =========================
   GAME CARD
========================= */


.game {

  position: relative;

  padding: 30px;

  background: rgba(255, 250, 242, .72);

  border: 1px solid rgba(255,255,255,.8);

  border-radius: 32px;

  box-shadow: var(--shadow);

  backdrop-filter: blur(15px);

  overflow: hidden;
}


.game::before {

  content: "꧁";

  position: absolute;

  top: 10px;

  left: 15px;

  color: var(--gold);

  opacity: .2;

  font-size: 35px;
}


.game::after {

  content: "꧂";

  position: absolute;

  bottom: 10px;

  right: 15px;

  color: var(--gold);

  opacity: .2;

  font-size: 35px;
}


/* =========================
   PLAYERS
========================= */


.players {

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

  border-radius: 18px;

  border: 1px solid transparent;

  background: rgba(255,255,255,.45);

  transition: .3s ease;
}


.player.active {

  background: rgba(255,255,255,.9);

  border-color: rgba(181,138,78,.25);

  transform: translateY(-3px);

  box-shadow:
    0 10px 25px rgba(75,56,48,.1);
}


.player small {

  display: block;

  font-size: 8px;

  letter-spacing: 2px;

  color: var(--brown-light);
}


.player h2 {

  font-family: "Cormorant Garamond", serif;

  font-size: 24px;

  line-height: 1;
}


.avatar {

  width: 40px;

  height: 40px;

  border-radius: 50%;

  flex-shrink: 0;

  box-shadow:

    inset -5px -6px 8px rgba(0,0,0,.16),

    inset 4px 4px 7px rgba(255,255,255,.4),

    0 5px 10px rgba(0,0,0,.12);
}


.avatar.red {

  background:
    radial-gradient(
      circle at 30% 25%,
      var(--red-light),
      var(--red)
    );
}


.avatar.blue {

  background:
    radial-gradient(
      circle at 30% 25%,
      var(--blue-light),
      var(--blue)
    );
}


.vs {

  width: 40px;

  height: 40px;

  display: grid;

  place-items: center;

  border-radius: 50%;

  background: var(--brown);

  color: white;

  font-size: 9px;

  font-weight: 700;
}


/* =========================
   GAME INFO
========================= */


.game-info {

  text-align: center;

  margin: 25px auto;
}


.turn span {

  display: block;

  font-size: 8px;

  letter-spacing: 3px;

  color: var(--brown-light);
}


.turn strong {

  display: block;

  margin-top: 2px;

  font-family: "Cormorant Garamond", serif;

  font-size: 25px;
}


#message {

  margin-top: 10px;

  font-size: 11px;

  color: var(--brown-light);
}


/* =========================
   BOARD
========================= */


.board-section {

  display: flex;

  justify-content: center;

  margin: 15px 0 30px;
}


.board {

  position: relative;

  width: min(75vw, 400px);

  aspect-ratio: 1;

  border-radius: 24px;

  background:

    radial-gradient(
      circle at center,
      #f5ead7,
      #e5cfaf
    );

  box-shadow:

    inset 0 0 0 8px rgba(255,255,255,.25),

    0 20px 40px rgba(75,56,48,.16);
}


/* BOARD LINES */


.h-line,
.v-line,
.d-line {

  position: absolute;

  display: block;

  background: rgba(75,56,48,.55);

  pointer-events: none;
}


.h-line {

  left: 12%;

  width: 76%;

  height: 2px;
}


.h1 {
  top: 12%;
}


.h2 {
  top: 50%;

  transform: translateY(-50%);
}


.v-line {

  top: 12%;

  width: 2px;

  height: 76%;
}


.v1 {
  left: 12%;
}


.v2 {

  left: 50%;

  transform: translateX(-50%);
}


.d-line {

  width: 108%;

  height: 2px;

  left: -4%;

  top: 50%;
}


.d1 {

  transform: rotate(45deg);
}


.d2 {

  transform: rotate(-45deg);
}


/* =========================
   POINT
========================= */


.point {

  position: absolute;

  width: 16%;

  height: 16%;

  transform: translate(-50%, -50%);

  border: 4px solid var(--card);

  border-radius: 50%;

  background: var(--brown);

  cursor: pointer;

  z-index: 5;

  transition:
    transform .2s ease,
    box-shadow .2s ease;
}


.point[data-position="0"] {
  top: 12%;
  left: 12%;
}


.point[data-position="1"] {
  top: 12%;
  left: 50%;
}


.point[data-position="2"] {
  top: 12%;
  left: 88%;
}


.point[data-position="3"] {
  top: 50%;
  left: 12%;
}


.point[data-position="4"] {
  top: 50%;
  left: 50%;
}


.point[data-position="5"] {
  top: 50%;
  left: 88%;
}


.point[data-position="6"] {
  top: 88%;
  left: 12%;
}


.point[data-position="7"] {
  top: 88%;
  left: 50%;
}


.point[data-position="8"] {
  top: 88%;
  left: 88%;
}


.point:hover {

  transform:
    translate(-50%, -50%)
    scale(1.1);
}


.point.selected {

  box-shadow:

    0 0 0 5px rgba(181,138,78,.35);

  transform:
    translate(-50%, -50%)
    scale(1.12);
}


.point.movable {

  background: var(--gold);

  animation: pulse 1.2s infinite;
}


/* =========================
   PIECES
========================= */


.piece {

  position: absolute;

  inset: 14%;

  border-radius: 50%;

  pointer-events: none;

  animation: appear .25s ease;

  box-shadow:

    inset -6px -7px 10px rgba(0,0,0,.18),

    inset 5px 5px 8px rgba(255,255,255,.4),

    0 5px 9px rgba(0,0,0,.2);
}


.piece.red {

  background:

    radial-gradient(
      circle at 30% 25%,
      #efaaa0,
      var(--red) 65%,
      #773535
    );
}


.piece.blue {

  background:

    radial-gradient(
      circle at 30% 25%,
      #c1d4e6,
      var(--blue) 65%,
      #344d68
    );
}


/* =========================
   SCORE
========================= */


.score {

  display: grid;

  grid-template-columns: 1fr 1fr 1fr;

  max-width: 500px;

  margin: auto;

  border-top: 1px solid rgba(75,56,48,.12);

  border-bottom: 1px solid rgba(75,56,48,.12);
}


.score-item {

  position: relative;

  padding: 14px;

  text-align: center;

  border-right: 1px solid rgba(75,56,48,.12);
}


.score-item:last-child {

  border-right: none;
}


.score-item small {

  display: block;

  font-size: 8px;

  letter-spacing: 2px;

  color: var(--brown-light);
}


.score-item strong {

  font-family: "Cormorant Garamond", serif;

  font-size: 30px;
}


.score-color {

  display: inline-block;

  width: 7px;

  height: 7px;

  border-radius: 50%;

  margin-right: 4px;
}


.score-color.red {
  background: var(--red);
}


.score-color.blue {
  background: var(--blue);
}


/* =========================
   BUTTON
========================= */


.reset {

  display: block;

  margin: 25px auto 0;

  padding: 12px 28px;

  border: none;

  border-radius: 50px;

  background: var(--brown);

  color: white;

  font-family: inherit;

  font-size: 11px;

  cursor: pointer;

  transition: .3s ease;
}


.reset:hover {

  background: var(--red);

  transform: translateY(-2px);

  box-shadow:
    0 10px 20px rgba(169,79,79,.2);
}


/* =========================
   FOOTER
========================= */


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


/* =========================
   MODAL
========================= */


.modal {

  position: fixed;

  inset: 0;

  display: none;

  place-items: center;

  padding: 20px;

  background: rgba(55,40,35,.45);

  backdrop-filter: blur(8px);

  z-index: 100;
}


.modal.show {

  display: grid;

  animation: fade .25s ease;
}


.modal-box {

  width: min(90%, 380px);

  padding: 40px 25px;

  text-align: center;

  border-radius: 30px;

  background: var(--card);

  box-shadow:
    0 30px 80px rgba(0,0,0,.25);

  animation: popup .35s ease;
}


.ornament {

  font-size: 40px;

  color: var(--gold);
}


.modal-box > p {

  margin-top: 5px;

  font-size: 9px;

  letter-spacing: 3px;

  color: var(--brown-light);
}


.modal-box h2 {

  margin: 5px 0 20px;

  font-family: "Cormorant Garamond", serif;

  font-size: 42px;

  color: var(--red);
}


.winner-piece {

  width: 55px;

  height: 55px;

  margin: 0 auto 25px;

  border-radius: 50%;

  box-shadow:

    inset -7px -7px 10px rgba(0,0,0,.18),

    inset 5px 5px 8px rgba(255,255,255,.4),

    0 8px 15px rgba(0,0,0,.15);
}


.winner-piece.red {

  background:
    radial-gradient(
      circle at 30% 25%,
      #efaaa0,
      var(--red) 65%,
      #773535
    );
}


.winner-piece.blue {

  background:
    radial-gradient(
      circle at 30% 25%,
      #c1d4e6,
      var(--blue) 65%,
      #344d68
    );
}


#playAgain {

  border: none;

  padding: 12px 30px;

  border-radius: 50px;

  background: var(--brown);

  color: white;

  font-family: inherit;

  cursor: pointer;

  transition: .3s ease;
}


#playAgain:hover {

  background: var(--red);

  transform: translateY(-2px);
}


/* =========================
   ANIMATION
========================= */


@keyframes pulse {

  0%, 100% {

    box-shadow:
      0 0 0 3px rgba(181,138,78,.15);
  }

  50% {

    box-shadow:
      0 0 0 9px rgba(181,138,78,.25);
  }

}


@keyframes appear {

  from {

    opacity: 0;

    transform: scale(.4);
  }

  to {

    opacity: 1;

    transform: scale(1);
  }

}


@keyframes fade {

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

    transform:
      translateY(20px)
      scale(.9);
  }

  to {

    opacity: 1;

    transform:
      translateY(0)
      scale(1);
  }

}


/* =========================
   MOBILE
========================= */


@media (max-width: 600px) {

  body {
    padding: 20px 10px;
  }


  .game {
    padding: 22px 14px;

    border-radius: 25px;
  }


  .players {
    gap: 6px;
  }


  .player {
    padding: 8px;

    gap: 7px;
  }


  .avatar {
    width: 30px;
    height: 30px;
  }


  .player h2 {
    font-size: 18px;
  }


  .player small {
    font-size: 6px;
  }


  .vs {
    width: 32px;
    height: 32px;

    font-size: 8px;
  }


  .board {
    width: min(88vw, 360px);
  }


  .game-info {
    margin: 20px auto;
  }

}
