// See the shakacode/shakapacker README and docs directory for advice on customizing your webpackConfig.
const { generateWebpackConfig, merge } = require('shakapacker')

const ForkTSCheckerWebpackPlugin = require("fork-ts-checker-webpack-plugin");

const webpackConfig = generateWebpackConfig()

module.exports = merge(webpackConfig, {
  plugins: [new ForkTSCheckerWebpackPlugin()],
});