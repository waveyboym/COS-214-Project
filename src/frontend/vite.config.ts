import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'

export default defineConfig({
  plugins: [react()],
  css: {
    devSourcemap: true
  },
  resolve: {
    alias: {
      // Add any aliases you may need here
    }
  },
  build: {
    // Add any build configuration here
  },
  server: {
    // Add server configuration here
  },
  // Enable JSX for .js files
  esbuild: {
    jsxFactory: 'React.createElement',
    jsxFragment: 'React.Fragment'
  }
})
