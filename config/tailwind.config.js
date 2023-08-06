/** @type {import('tailwindcss').Config} */
module.exports = {
    daisyui: {
      themes: [
        {
          mytheme: {
  "primary": "#be123c",
  "secondary": "#8b5cf6",
  "accent": "#1fb2a6",
  "neutral": "#2a323c",
  "base-100": "#1d232a",
  "info": "#3abff8",
  "success": "#36d399",
  "warning": "#fbbd23",
  "error": "#f87272",
          },
        },
      ],
    },
  content: [
    './app/helpers/**/*.rb',
    './app/javascript/**/*.tsx',
    './app/views/**/*',
  ],
  theme: {
    extend: {},
  },
  plugins: [require("daisyui")],
}

